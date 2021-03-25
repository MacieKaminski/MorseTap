#define INT_SOURCE        0x0C 
#define REG_WHO_AM_I      0x1D
#define HP_FILTER_CUTOFF  0x0F 
#define PULSE_CFG         0x21 
#define PULSE_SRC         0x22 
#define PULSE_THSX        0x23 
#define PULSE_THSY        0x24 
#define PULSE_THSZ        0x25 
#define PULSE_TMLT        0x26 
#define PULSE_LTCY        0x27 
#define PULSE_WIND        0x28 
#define CTRL_REG1     		0x2A 
#define CTRL_REG2         0x2B
#define CTRL_REG4         0x2D 
#define CTRL_REG5         0x2E 
#define REG_OUT_X_MSB     0x01
#define REG_OUT_Y_MSB     0x03
#define REG_OUT_Z_MSB     0x05

void Mma8451q_Init(void);
