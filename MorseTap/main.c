#include "frdm_bsp.h" 
#include "led.h" 
#include "uart.h" 
#include "stdio.h"
#include "i2c.h"
#include "string.h"
#include "mma8451q.h"
#include "convert.h"

void SysTick_Handler(void);
void PORTA_IRQHandler(void);

static uint16_t msTicks = 0;
static uint8_t newTick = 0;
static uint8_t readout = 0;
static char letter[5]= "00000";
static uint8_t iterator = 0;

int main (void) 
{ 
	SysTick_Config(1000000); 								/* initialize system timer */
	LED_Init ();	 													/* initialize all LEDs */ 
	LED_Welcome();  												/* blink with all LEDs */
	
	UART_Init(9600);												/* initialize UART */ 
	UART_Println("\n\r### Morse Tap Project ###");

	I2C_Init();															/* initialize I2C */

	UART_Println("\n-> Starting the main loop. Sleep ...\n\r");

	Mma8451q_Init();
	
	while(1)
	{
		__WFI();
		
		if(newTick == 1)
		{
			newTick = 0;
			
			if(msTicks % 100 == 0)
			{
				convert(letter);
				iterator = 0;
				letter[0] = '0';
				letter[1] = '0';
				letter[2] = '0';
				letter[3] = '0';
				letter[4] = '0';
			}
			
			if(msTicks % 300 == 0)
			{
				msTicks = 0;
				UART_Print(" ");
			}
		}
	}
}

void PORTA_IRQHandler(void){

PORTA -> PCR[10] |= PORT_PCR_ISF_MASK;
	
I2C_ReadReg(REG_WHO_AM_I,INT_SOURCE, &readout);
	
			
			if ((readout & 0x08)==0x08) // Read EA bit to check if a interrupt was generated
			{
				 
				I2C_ReadReg(REG_WHO_AM_I, PULSE_SRC, &readout);
				
				if(readout&(1<<3)){
					LED_Blink(LED_GREEN,100);
					
					letter[iterator-1] = '2';
					
				}
				else 
				{
					
					LED_Blink(LED_BLUE,100);
					
					msTicks = 0;
					
					if(iterator == 5)
					{
						iterator = 0;
						letter[0] = '0';
						letter[1] = '0';
						letter[2] = '0';
						letter[3] = '0';
						letter[4] = '0';
					}
					
					letter[iterator] = '1';
					iterator++;

				}
		}			
}

void SysTick_Handler(void) 
{
	msTicks++;
	newTick = 1;
}
