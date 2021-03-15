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

#include "../include/opamp.h"

void OPAMP_Initialize()
{
    OPAMP_DisableSystem();
    
    //TIMEBASE 3; 
    OPAMP.TIMEBASE = OPAMP_TIMEBASE_VALUE << OPAMP_TIMEBASE_gp;
    
    //DBGRUN enabled; 
    OPAMP.DBGCTRL = 0x01;
    
    //IRSEL FULL; 
    OPAMP.PWRCTRL = 0x00;
    
    //OP0 Configuration : Connected Directly to Pins
    
    //MUXNEG INN; MUXPOS INP; 
    OPAMP.OP0INMUX = 0x00;
    
    //MUXWIP WIP0; MUXBOT OFF; MUXTOP OFF; 
    OPAMP.OP0RESMUX = 0x00;
    
    //RUNSTBY disabled; OUTMODE OFF; EVENTEN enabled; ALWAYSON disabled; 
    OPAMP.OP0CTRLA = 0x02;
    
    //SETTLE 127; 
    OPAMP.OP0SETTLE = 0x7F;
    
    //OP1 Configuration : Non-Inverting Programmable Gain Amplifier
    //OP1 Gain : 16.0
    
    //MUXNEG WIP; MUXPOS INP; 
    OPAMP.OP1INMUX = 0x10;
    
    //MUXWIP WIP7; MUXBOT GND; MUXTOP OUT; 
    OPAMP.OP1RESMUX = 0xF5;
    
    //RUNSTBY disabled; OUTMODE NORMAL; EVENTEN disabled; ALWAYSON enabled; 
    OPAMP.OP1CTRLA = 0x05;
    
    //SETTLE 127; 
    OPAMP.OP1SETTLE = 0x7F;
    
    //OP2 Configuration : Non-Inverting Programmable Gain Amplifier
    //OP2 Gain : 4.0
    
    //MUXNEG WIP; MUXPOS LINKOUT; 
    OPAMP.OP2INMUX = 0x15;
    
    //MUXWIP WIP5; MUXBOT GND; MUXTOP OUT; 
    OPAMP.OP2RESMUX = 0xB5;
    
    //RUNSTBY disabled; OUTMODE NORMAL; EVENTEN disabled; ALWAYSON enabled; 
    OPAMP.OP2CTRLA = 0x05;
    
    //SETTLE 127; 
    OPAMP.OP2SETTLE = 0x7F;
    
    OPAMP_EnableSystem();
}

void OPAMP_EnableSystem(void)
{
    OPAMP.CTRLA |= OPAMP_ENABLE_bm;
}

void OPAMP_DisableSystem(void)
{
    OPAMP.CTRLA &= ~OPAMP_ENABLE_bm;
}

//OP1 Non-Inverting Programmable Gain Amplifier APIs

void OPAMP_SetOP1PositiveInMux(OPAMP_OP1INMUX_MUXPOS_t value)
{
    OPAMP.OP1INMUX = (OPAMP.OP1INMUX & ~OPAMP_MUXPOS_gm) | value;
}

void OPAMP_SetOP1WiperResMux(OPAMP_OP1RESMUX_MUXWIP_t value)
{
    OPAMP.OP1RESMUX = (OPAMP.OP1RESMUX & ~OPAMP_MUXWIP_gm) | value;
}

void OPAMP_SetOP1SettleTime(uint8_t settleTime)
{
    if (settleTime > 127) {
        settleTime = 127;
    }
    OPAMP.OP1SETTLE = settleTime;
}

bool OPAMP_IsOP1Settled(void)
{
    return OPAMP.OP1STATUS > 0;
}

void OPAMP_SetOP1OffsetCalibration(uint8_t calValue)
{
    OPAMP.OP1CAL = calValue;
}

//OP2 Non-Inverting Programmable Gain Amplifier APIs

void OPAMP_SetOP2PositiveInMux(OPAMP_OP2INMUX_MUXPOS_t value)
{
    OPAMP.OP2INMUX = (OPAMP.OP2INMUX & ~OPAMP_MUXPOS_gm) | value;
}

void OPAMP_SetOP2WiperResMux(OPAMP_OP2RESMUX_MUXWIP_t value)
{
    OPAMP.OP2RESMUX = (OPAMP.OP2RESMUX & ~OPAMP_MUXWIP_gm) | value;
}

void OPAMP_SetOP2SettleTime(uint8_t settleTime)
{
    if (settleTime > 127) {
        settleTime = 127;
    }
    OPAMP.OP2SETTLE = settleTime;
}

bool OPAMP_IsOP2Settled(void)
{
    return OPAMP.OP2STATUS > 0;
}

void OPAMP_SetOP2OffsetCalibration(uint8_t calValue)
{
    OPAMP.OP2CAL = calValue;
}
