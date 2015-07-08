/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-13, 12:10, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


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
#include "WAIT1.h"
#include "TFC_LMOT.h"
#include "PwmLdd2.h"
#include "TU3.h"
#include "TFC_RMOT.h"
#include "PwmLdd3.h"
#include "TFC_EMOT.h"
#include "BitIoLdd3.h"
#include "CsIO1.h"
#include "IO1.h"
#include "TU1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "TFC_Controller.h"


int 	counter=0,errorR=0,errorL=0;
float 	error=0,errorp=0,errorint=0,errorder=0,ki=0.0,kd=0.0,kp=9,correction=0,de=0;
word	Rearspeed=249;

extern word TAOS_VAL[128],TAOS_DIG[128],TAOS_DIG2[128];
extern float TAOS_DER[128];

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your code here */
  /* For example: for(;;) { } */
  printf("hello world\n\r");
  for(;;) { 
	  //TFC_EMOT_ClearVal();
	  //while
	  TFC_EMOT_SetVal();
	  switch(Curr_Task)
	  {
	  	  case WAIT_TASK:
		  	  	  TFC_ADCI_MeasureChan(FALSE,POT_1);				//Function used to read POT1 value
		  	  	  TFC_ADCI_GetChanValue16(POT_1,&Rearspeed);		//Function to save POT1 value in Rearspeed variable
		  	  	  Rearspeed=Rearspeed/65;							//Function used to convert POT1 value in range 0-1000 for motor compatibility		  	  	
	  		  break;
	  	  case TAOS_TASK:
	  		  	  TFC_TAOS_READ();									//Function used to read one frame of the camera
	  		  	  Curr_Task=WAIT_TASK;
	  		  break;	
	  	  case RS232_TASK:
	  		  	  
	  		  	  Curr_Task=WAIT_TASK;
	  		  break;	  		  
	  	  case CONTROL_TASK:	
	  		  	  TFC_DERIVATIVE(TAOS_VAL,TAOS_DER,127);			//Function used to obtain an array with derivative value(%) of the camera frame	  		  	  
	  		  	  TFC_DIGITALIZE_DER(TAOS_DER,TAOS_DIG2,1.5,128);
	  		  	  
	  		  	  TFC_GET_ERROR(TAOS_DIG2, &errorR, &errorL,&error,50);	//Function used to get error based on derivative digitilezed array		
	  		  	   		  	  
	  		  	  de=error-errorp;									//Obtain derivative from past error
	  		  	  de=de<0?(de*(-1)):de;								//Absolute value of derivative from past error
	  		  	  if(de>30) error=errorp;							//If derivative is greater than limit, actual error equal to past error
	  		  	  
	  		  	  correction=error*9;
	  		  	  if(correction>350)correction=350;
	  		  	  if(correction<-350) correction=-350;
	  		  	  errorp=error;
	  		  	  
	  		  	  TFC_SERVO_SetDutyUS(18670+correction);			//18150
	  		  	  TFC_LMOT_SetDutyUS(Rearspeed+(correction/2));TFC_RMOT_SetDutyUS(Rearspeed-(correction/2));
	  		  	  LED_PRINT_ERROR(error);
	  		  	  Curr_Task=WAIT_TASK;
	  		  	
	  		  break;
	  	  default:
	  		  	  Curr_Task=WAIT_TASK;
	  		  break;	  		  
	  }
	
  } 
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
