/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PwmLdd2.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PWM_LDD
**     Version     : Component 01.003, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-04-27, 15:15, # CodeGen: 62
**     Abstract    :
**          This component implements a pulse-width modulation generator
**          that generates signal with variable duty and fixed cycle.
**          This PWM component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : PwmLdd2
**          Period device                                  : TPM0_MOD
**          Duty device                                    : TPM0_C0V
**          Output pin                                     : ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0
**          Output pin signal                              : 
**          Counter                                        : TPM0_CNT
**          Interrupt service/event                        : Disabled
**          Period                                         : 1000 �s
**          Starting pulse width                           : 900 �s
**          Initial polarity                               : low
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnEnd                                      : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked component                             : TU3
**     Contents    :
**         Init       - LDD_TDeviceData* PwmLdd2_Init(LDD_TUserData *UserDataPtr);
**         SetRatio16 - LDD_TError PwmLdd2_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);
**         SetDutyUS  - LDD_TError PwmLdd2_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PwmLdd2.h
** @version 01.01
** @brief
**          This component implements a pulse-width modulation generator
**          that generates signal with variable duty and fixed cycle.
**          This PWM component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup PwmLdd2_module PwmLdd2 module documentation
**  @{
*/         

#ifndef __PwmLdd2_H
#define __PwmLdd2_H

/* MODULE PwmLdd2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TU3.h"
#include "TPM_PDD.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define PwmLdd2_PERIOD_VALUE 0xBB80UL  /* Initial period value in ticks of the timer. */
#define PwmLdd2_PERIOD_VALUE_0 0xBB80UL /* Period value in ticks of the timer in clock configuration 0. */

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PwmLdd2_PRPH_BASE_ADDRESS  0x40038000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PwmLdd2_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PwmLdd2_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PwmLdd2_Init_METHOD_ENABLED    /*!< Init method of the component PwmLdd2 is enabled (generated) */
#define PwmLdd2_SetRatio16_METHOD_ENABLED /*!< SetRatio16 method of the component PwmLdd2 is enabled (generated) */
#define PwmLdd2_SetDutyUS_METHOD_ENABLED /*!< SetDutyUS method of the component PwmLdd2 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */



/*
** ===================================================================
**     Method      :  PwmLdd2_Init (component PWM_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* PwmLdd2_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PwmLdd2_SetRatio16 (component PWM_LDD)
*/
/*!
**     @brief
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PwmLdd2_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);

/*
** ===================================================================
**     Method      :  PwmLdd2_SetDutyUS (component PWM_LDD)
*/
/*!
**     @brief
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in <Starting pulse width>
**         property.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Time            - Duty to set [in microseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PwmLdd2_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/* END PwmLdd2. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PwmLdd2_H */
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
