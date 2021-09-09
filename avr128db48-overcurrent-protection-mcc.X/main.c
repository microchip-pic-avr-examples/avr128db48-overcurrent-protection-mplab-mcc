/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. 
    
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

#include "mcc_generated_files/mcc.h"

/*
    Main application
*/

#define CLK_PER 4000000ul
#define OPAMP_MAX_SETTLE_TIME 0x7F
#define VREF_AC_MV 4096
#define AC_TRIGGER_VOLTAGE_MV_INIT 1100


#include <math.h>
#include <util/delay.h>
#include <avr/io.h>



void fan_start(void);
void ac_trig_event_enable(void);
void BTN_interrupt(void);
void ccl_init(void);

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    ccl_init();//this init function will be swapped with MCC code once a filed bug is sorted out.
    fan_start();
    sei();
    PORTB_BTN_SetInterruptHandler(&BTN_interrupt);
    /* Replace with your application code */
    while (1){
    }
}


void tcd_enable(void)
{
	TCD0.CTRLA = TCD_ENABLE_bm;
	while(!(TCD0.STATUS & TCD_ENRDY_bm));
}

uint8_t ac_calculate_trigger_voltage(uint16_t mV)
{
	volatile uint8_t triggerVoltage = (((uint32_t)mV*256)/VREF_AC_MV);
	return triggerVoltage;
}

void ac_calibration(void)
{
	PORTB.DIRSET = PIN3_bm;
	PORTB.OUTCLR = PIN3_bm;
	uint8_t calibrating = 1;
	uint16_t ac_trigger_voltage_mv=AC_TRIGGER_VOLTAGE_MV_INIT;
	AC0.INTCTRL = (0x03<<4);//AC_INTMODE_NORMAL_POSEDGE_gc
	_delay_ms(3000);
	while (calibrating)
	{
		ac_trigger_voltage_mv += 50;
		AC0.DACREF = ac_calculate_trigger_voltage(ac_trigger_voltage_mv);
		_delay_ms(200);//Allow some time for the flag to be raised
		if (!(AC0.STATUS & AC_CMPIF_bm))
		{
			calibrating=0;
			PORTB.OUTSET =PIN3_bm;
		}
		AC0.STATUS=AC_CMPIF_bm;
	}
	
}

void ac_trig_event_enable(void)
{
    AC0.INTCTRL = AC_INTMODE_NORMAL_POSEDGE_gc | AC_CMP_bm;
    EVSYS.SWEVENTA=EVSYS_SWEVENTA_CH1_gc;
	EVSYS.CHANNEL0=EVSYS_CHANNEL0_CCL_LUT0_gc;
	EVSYS.USERTCD0INPUTA=EVSYS_USER_CHANNEL0_gc;   
}
void ac_trig_event_disable(void)
{
    AC0.INTCTRL &= ~AC_CMP_bm;
	EVSYS.CHANNEL0=EVSYS_CHANNEL0_OFF_gc;
	EVSYS.USERTCD0INPUTA = EVSYS_USER_OFF_gc;
}

void fan_start(void)
{
	ac_trig_event_disable();
	tcd_enable();
	ac_calibration();
	ac_trig_event_enable();

}

void BTN_interrupt(void)
{
    fan_start();
}
void ccl_init(void)
{
    CCL.SEQCTRL0 = CCL_SEQSEL_RS_gc; // Create a RS latch
    /*Set up LUT0*/
    CCL.LUT0CTRLB = CCL_INSEL0_AC0_gc; // AC0 and mask all other bits
    CCL.TRUTH0 = 0x02; // When AC is hight hight output, otherwise low output
    CCL.LUT0CTRLA = CCL_ENABLE_bm | CCL_OUTEN_bm;
    PORTA.DIRSET = PIN3_bm;
   
    /*Set up LUT1*/
    EVSYS.USERCCLLUT1A = EVSYS_USER_CHANNEL1_gc;
    CCL.LUT1CTRLB = CCL_INSEL0_EVENTA_gc; // Event A as input and mask all other bits
    CCL.TRUTH1 = 0x02; // When Event A is hight hight output, otherwise low output
    CCL.LUT1CTRLA = CCL_ENABLE_bm;
   
    CCL.CTRLA = CCL_ENABLE_bm;
}
/**
    End of File
*/