/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "TFC_LEDS.h"
#include "BitsIoLdd1.h"
#include "TFC_DIPS.h"
#include "BitsIoLdd2.h"
#include "TFC_ADCI.h"
#include "AdcLdd1.h"
#include "TFC_INTE.h"
#include "TimerIntLdd1.h"
#include "TFC_SERVO.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "TFC_TSI.h"
#include "BitIoLdd1.h"
#include "TFC_TCLK.h"
#include "BitIoLdd2.h"
#include "TU1.h"

#include "TFC_Controller.h"


#define 	TAO0 			0
#define 	TAOS_ANALOG 	0
#define 	TAOS_DIGITAL 	1

word 		TAOS_VAL[128];
word 		TAOS_DIG[128];
word 		TAOS_DIG2[128];
float 		TAOS_DER[128];

void TFC_TAOS_READ(void)
{
	int i=0;
	TFC_TSI_SetVal();
	TFC_TCLK_SetVal();
	WAIT1_Waitus(1);
	TFC_TSI_ClrVal();
	TFC_TCLK_ClrVal();
	  for(i=0;i<127;i++){
	  	  TFC_TCLK_SetVal();
	  	  TFC_ADCI_MeasureChan(FALSE,TAOS_1);
	  	  TFC_TCLK_ClrVal();
	  	  TFC_ADCI_GetChanValue16(TAOS_1,&TAOS_VAL[i]);
	  	  }
}

void TFC_DIGITALIZE(word * ADC_VAL, word * DIG_VAL,word TRIGGER, int size)
{
	int counter=0;
	for(counter=0;counter<size;counter++)
		{
			if(*(ADC_VAL+counter)>TRIGGER) *(DIG_VAL+counter)=1;
			else *(DIG_VAL+counter)=0;
		}
}

void TFC_DIGITALIZE_DER(float * DER_VAL, word * DIG_VAL,float TRIGGER, int size)
{
	int counter=0;
	for(counter=0;counter<size;counter++)
		{
			if(*(DER_VAL+counter)>TRIGGER) *(DIG_VAL+counter)=0;
			else *(DIG_VAL+counter)=1;
		}
}
void TFC_DERIVATIVE(word * ADC_VAL, float * DER_VAL, int size)
{
	int counter=0;
	for(counter=0;counter<(size-1);counter++)
		{
			if(*(ADC_VAL+counter)>*(ADC_VAL+counter+1)) 
				{
					*(DER_VAL+counter)=(float)*(ADC_VAL+counter)/(float)*(ADC_VAL+counter+1);
				}
			else
				{
					*(DER_VAL+counter)=(float)*(ADC_VAL+counter+1)/(float)*(ADC_VAL+counter);
				}
		}
}
void TFC_GET_ERROR(word * DIG_VAL, int * errorR, int * errorL, float *error, int frame)
{
	*errorR=0;
	*errorL=0;
	int i=0;
	for(i=0;i<=frame;i++)
	{
		if(*(DIG_VAL+64+i)==0 && *errorR==0)
		{
			//*errorR=128-(65+i);
			*errorR=128-(65+i)-(63-frame);
		}
		if(*(DIG_VAL+(64-i))==0 && *errorL==0)
		{
			//*errorL=(64-i);
			*errorL=(64-i)-(64-frame);
		}
	}
  	  if(*errorL>0 && *errorR==0) *error=-(*errorL);//-12);
  	  else if(*errorL>0 && *errorR>0) *error=(*errorR-*errorL)/2;//-12;
  	  else if(*errorL==0 && *errorR>0) *error=*errorR;//-12;
}

void LED_PRINT_ERROR(float error)
{
  	  if(error<-25)					  	TFC_LEDS_PutVal(0b00000011);
  	  else if(error>-26 && error<-10)	TFC_LEDS_PutVal(0b00000111);
  	  else if(error>-9 && error<11)		TFC_LEDS_PutVal(0b00001111);
  	  else if(error>10 && error<26) 	TFC_LEDS_PutVal(0b00001110);
  	  else if(error>25) 				TFC_LEDS_PutVal(0b00001100);	
}
