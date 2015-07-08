/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-13, 12:10, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "TFC_Controller.h"

/*
 * 
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TFC_ADCI_OnEnd (module Events)
**
**     Component   :  TFC_ADCI [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TFC_ADCI_OnEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TFC_ADCI_OnCalibrationEnd (module Events)
**
**     Component   :  TFC_ADCI [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TFC_ADCI_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TFC_INTE_OnInterrupt (module Events)
**
**     Component   :  TFC_INTE [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TFC_INTE_OnInterrupt(void)
{
  /* Write your code here ... */
  if(!(TickCounter%2==0))
  {
	  	//if(TickCounter==1)	Curr_Task=LCD_TASK;
		if(TickCounter==1  || TickCounter==3)	Curr_Task=CONTROL_TASK;
		//if(TickCounter==9)					Curr_Task=RS232_TASK;
  }
  else if(TickCounter%2==0)
	  {
	  	  Curr_Task=TAOS_TASK;
	  }

  TickCounter++;
}

/*
** ===================================================================
**     Event       :  TFC_SERVO_OnEnd (module Events)
**
**     Component   :  TFC_SERVO [PWM]
**     Description :
**         This event is called when the specified number of cycles has
**         been generated. (Only when the component is enabled -
**         <Enable> and the events are enabled - <EnableEvent>). The
**         event is available only when the <Interrupt service/event>
**         property is enabled and selected peripheral supports
**         appropriate interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TFC_SERVO_OnEnd(void)
{
  /* Write your code here ... */TickCounter=1;Curr_Task=TAOS_TASK;
}




/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
