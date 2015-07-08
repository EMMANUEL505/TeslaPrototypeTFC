#define WAIT_TASK		0
#define TAOS_TASK 		1
#define LCD_TASK 		2
#define RS232_TASK		3
#define CONTROL_TASK	4

#define TAOS_1			0
#define TAOS_2			1
#define POT_1			2	
#define POT_2			3


int TickCounter;
int Curr_Task;

void TFC_TAOS_READ(void);
void TFC_DIGITALIZE(word * ADC_VAL, word * DIG_VAL,word TRIGGER, int size);
void TFC_DIGITALIZE_DER(float * DER_VAL, word * DIG_VAL,float TRIGGER, int size);
void TFC_DERIVATIVE(word * ADC_VAL, float * DER_VAL, int size);
void TFC_GET_ERROR(word * DIG_VAL, int *errorR, int *errorL, float *error, int frame);
void LED_PRINT_ERROR(float error);
