#include "frdm_bsp.h" 
#include "led.h" 
#include "uart.h" 
#include "stdio.h"
#include "i2c.h"
#include "string.h"
#include "mma8451q.h"

void Mma8451q_Init(void);

static uint8_t ctrl_reg1_data = 0;

void Mma8451q_Init(void)
{

	SIM->SCGC5 |=  SIM_SCGC5_PORTA_MASK;
	PORTA->PCR[10] |= (0 | PORT_PCR_ISF_MASK |  // Clear the interrupt flag
                       PORT_PCR_MUX(0x1)|     // PTA10 is configured as GPIO
                       PORT_PCR_IRQC(0xA));   // PTA10 is configured for falling edge interrupts
	NVIC_ClearPendingIRQ(30);
	NVIC_EnableIRQ(30);
	NVIC_SetPriority(30, 4);
	
	I2C_WriteReg(REG_WHO_AM_I, CTRL_REG1,0x10); //200 Hz, Standby Mode
	I2C_WriteReg(REG_WHO_AM_I, CTRL_REG2, 0x02);
	//Step 2: Enable X, Y, Z Single Pulse and X, Y and Z Double Pulse with DPA = 0 no double pulse abort
	I2C_WriteReg(0x1D, PULSE_CFG, 0x3F);

	//Step 3: Set Threshold 2g on X and Y and 4g on Z
	//Note: Every step is 0.063g
	//2g / 0.063g = 32 counts
	//4g/ 0.063g = 64 counts
	I2C_WriteReg(REG_WHO_AM_I, PULSE_THSX, 0x64); //Set X Threshold to 1g
	I2C_WriteReg(REG_WHO_AM_I, PULSE_THSY, 0x64); //Set Y Threshold to 1g
	I2C_WriteReg(REG_WHO_AM_I, PULSE_THSZ, 0x64); //Set Z Threshold to 1g

	//Step 4: Set Time Limit for Tap Detection to 60 ms (LP Mode, 200 Hz ODR, No LPF)
	//Note: 200 Hz ODR LP Mode, Time step is 2.5 ms per step
	//60 ms /2.5 ms = 24 counts
	I2C_WriteReg(REG_WHO_AM_I, PULSE_TMLT,0x18); //60 ms czas trwania stukniecia max

	//Step 5: Set Latency Timer to 200 ms
	//Note: 200 Hz ODR LP Mode, Time step is 5 ms per step
	//200 ms/ 5 ms = 40 counts
	I2C_WriteReg(REG_WHO_AM_I, PULSE_LTCY,0x50); //400 ms 

	//Step 6: Set Time Window for Second Tap to 300 ms
	//Note: 200 Hz ODR LP Mode, Time step is 5 ms per step
	//300 ms/5 ms = 60 counts
	I2C_WriteReg(REG_WHO_AM_I, PULSE_WIND,0x3C); //300 ms

	//Step 7: Route INT1 to System Interrupt
	I2C_WriteReg(REG_WHO_AM_I, CTRL_REG4, 0x08); //Enable Pulse Interrupt Block in System CTRL_REG4
	I2C_WriteReg(REG_WHO_AM_I, CTRL_REG5, 0xF7); //Route Pulse Interrupt Block to INT1 hardware Pin // PTA10/IRQ12

	//Step 8: Active Mode
	//Read out the contents of the register
	//Change the value in the register to Active Mode.
	I2C_ReadReg (REG_WHO_AM_I,  CTRL_REG1, &ctrl_reg1_data);
	ctrl_reg1_data|= 0x01;
	I2C_WriteReg(REG_WHO_AM_I,CTRL_REG1, ctrl_reg1_data);

	UART_Println("\n\r ~~~~ TAP DETECTION ON: ~~~~ ");
}
