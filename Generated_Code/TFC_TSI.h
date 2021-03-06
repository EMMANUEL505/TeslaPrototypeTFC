/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TFC_TSI.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-04-18, 11:14, # CodeGen: 60
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       80            |  PTD7/SPI1_MISO/UART0_TX/SPI1_MOSI
**             ----------------------------------------------------
**
**         Port name                   : PTD
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : 0x0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIOD_PDOR [0x400FF0C0]
**         Port control register       : GPIOD_PDDR [0x400FF0D4]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool TFC_TSI_GetVal(void);
**         PutVal - void TFC_TSI_PutVal(bool Val);
**         ClrVal - void TFC_TSI_ClrVal(void);
**         SetVal - void TFC_TSI_SetVal(void);
**         NegVal - void TFC_TSI_NegVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TFC_TSI.h
** @version 01.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup TFC_TSI_module TFC_TSI module documentation
**  @{
*/         

#ifndef __TFC_TSI_H
#define __TFC_TSI_H

/* MODULE TFC_TSI. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "BitIoLdd1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  TFC_TSI_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define TFC_TSI_GetVal() (BitIoLdd1_GetVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TSI_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TSI_PutVal(Val) (BitIoLdd1_PutVal(BitIoLdd1_DeviceData, (Val)))

/*
** ===================================================================
**     Method      :  TFC_TSI_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TSI_ClrVal() (BitIoLdd1_ClrVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TSI_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TSI_SetVal() (BitIoLdd1_SetVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TSI_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TSI_NegVal() (BitIoLdd1_NegVal(BitIoLdd1_DeviceData))

/* END TFC_TSI. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TFC_TSI_H */
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
