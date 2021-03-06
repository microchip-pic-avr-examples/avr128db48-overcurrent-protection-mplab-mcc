/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/ac0.h"

int8_t AC0_Initialize()
{
    
    //WINSEL DISABLED; 
    AC0.CTRLB = 0x00;
    
    //DACREF 18; 
    AC0.DACREF = 0x12;
    
    //INTMODE BOTHEDGE; CMP disabled; 
    AC0.INTCTRL = 0x00;
    
    //INVERT disabled; INITVAL LOW; MUXPOS AINP2; MUXNEG DACREF; 
    AC0.MUXCTRL = 0x13;
    
    //RUNSTDBY disabled; OUTEN enabled; POWER PROFILE0; HYSMODE NONE; ENABLE enabled; 
    AC0.CTRLA = 0x41;
    
	return 0;
}

ISR(AC0_AC_vect)
{
	/* Insert your AC interrupt handling code here */

	/* The interrupt flag has to be cleared manually */
	AC0.STATUS = AC_CMPIF_bm;
}