/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TFC_TCLK.h
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
**                       2             |  PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL
**             ----------------------------------------------------
**
**         Port name                   : PTE
**
**         Bit number (in port)        : 1
**         Bit mask of the port        : 0x0002
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool TFC_TCLK_GetVal(void);
**         PutVal - void TFC_TCLK_PutVal(bool Val);
**         ClrVal - void TFC_TCLK_ClrVal(void);
**         SetVal - void TFC_TCLK_SetVal(void);
**         NegVal - void TFC_TCLK_NegVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TFC_TCLK.h
** @version 01.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup TFC_TCLK_module TFC_TCLK module documentation
**  @{
*/         

#ifndef __TFC_TCLK_H
#define __TFC_TCLK_H

/* MODULE TFC_TCLK. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "BitIoLdd2.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  TFC_TCLK_GetVal (component BitIO)
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
#define TFC_TCLK_GetVal() (BitIoLdd2_GetVal(BitIoLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TCLK_PutVal (component BitIO)
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
#define TFC_TCLK_PutVal(Val) (BitIoLdd2_PutVal(BitIoLdd2_DeviceData, (Val)))

/*
** ===================================================================
**     Method      :  TFC_TCLK_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TCLK_ClrVal() (BitIoLdd2_ClrVal(BitIoLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TCLK_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TCLK_SetVal() (BitIoLdd2_SetVal(BitIoLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  TFC_TCLK_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TFC_TCLK_NegVal() (BitIoLdd2_NegVal(BitIoLdd2_DeviceData))

/* END TFC_TCLK. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __TFC_TCLK_H */
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
