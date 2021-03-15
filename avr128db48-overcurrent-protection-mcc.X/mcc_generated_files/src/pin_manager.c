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


#include "../include/pin_manager.h"
static void (*PORTD_PD5_InterruptHandler)(void);
static void (*PORTB_BTN_InterruptHandler)(void);
static void (*PORTD_PD4_InterruptHandler)(void);
static void (*PORTA_IO_PA3_InterruptHandler)(void);
static void (*PORTA_PA7_InterruptHandler)(void);
static void (*PORTF_PF0_InterruptHandler)(void);
static void (*PORTE_PE2_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0x80;
    PORTB.DIR = 0x00;
    PORTC.DIR = 0x00;
    PORTD.DIR = 0x00;
    PORTE.DIR = 0x00;
    PORTF.DIR = 0x01;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x00;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x00;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x00;
    PORTB.PIN2CTRL = 0x0B;
    PORTB.PIN3CTRL = 0x00;
    PORTB.PIN4CTRL = 0x00;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x00;
    PORTD.PIN1CTRL = 0x04;
    PORTD.PIN2CTRL = 0x04;
    PORTD.PIN3CTRL = 0x04;
    PORTD.PIN4CTRL = 0x04;
    PORTD.PIN5CTRL = 0x04;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x04;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x04;
    PORTE.PIN2CTRL = 0x04;
    PORTE.PIN3CTRL = 0x04;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x00;
    PORTF.PIN5CTRL = 0x00;
    PORTF.PIN6CTRL = 0x00;
    PORTF.PIN7CTRL = 0x00;

    /* Multi-pin Config registers Initialization */
    PORTA.PINCONFIG = 0x00;
    PORTA.PINCTRLCLR = 0x00;
    PORTA.PINCTRLSET = 0x00;
    PORTA.PINCTRLUPD = 0x00;
    PORTB.PINCONFIG = 0x00;
    PORTB.PINCTRLCLR = 0x00;
    PORTB.PINCTRLSET = 0x00;
    PORTB.PINCTRLUPD = 0x00;
    PORTC.PINCONFIG = 0x00;
    PORTC.PINCTRLCLR = 0x00;
    PORTC.PINCTRLSET = 0x00;
    PORTC.PINCTRLUPD = 0x00;
    PORTD.PINCONFIG = 0x00;
    PORTD.PINCTRLCLR = 0x00;
    PORTD.PINCTRLSET = 0x00;
    PORTD.PINCTRLUPD = 0x00;
    PORTE.PINCONFIG = 0x00;
    PORTE.PINCTRLCLR = 0x00;
    PORTE.PINCTRLSET = 0x00;
    PORTE.PINCTRLUPD = 0x00;
    PORTF.PINCONFIG = 0x00;
    PORTF.PINCTRLCLR = 0x00;
    PORTF.PINCTRLSET = 0x00;
    PORTF.PINCTRLUPD = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x00;
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.SPIROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TCDROUTEA = 0x02;
    PORTMUX.TWIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;
    PORTMUX.USARTROUTEB = 0x00;
    PORTMUX.ZCDROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTD_PD5_SetInterruptHandler(PORTD_PD5_DefaultInterruptHandler);
    PORTB_BTN_SetInterruptHandler(PORTB_BTN_DefaultInterruptHandler);
    PORTD_PD4_SetInterruptHandler(PORTD_PD4_DefaultInterruptHandler);
    PORTA_IO_PA3_SetInterruptHandler(PORTA_IO_PA3_DefaultInterruptHandler);
    PORTA_PA7_SetInterruptHandler(PORTA_PA7_DefaultInterruptHandler);
    PORTF_PF0_SetInterruptHandler(PORTF_PF0_DefaultInterruptHandler);
    PORTE_PE2_SetInterruptHandler(PORTE_PE2_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTD_PD5 at application runtime
*/
void PORTD_PD5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD5_InterruptHandler = interruptHandler;
}

void PORTD_PD5_DefaultInterruptHandler(void)
{
    // add your PORTD_PD5 interrupt custom code
    // or set custom function using PORTD_PD5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_BTN at application runtime
*/
void PORTB_BTN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_BTN_InterruptHandler = interruptHandler;
}

void PORTB_BTN_DefaultInterruptHandler(void)
{
    // add your PORTB_BTN interrupt custom code
    // or set custom function using PORTB_BTN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD4 at application runtime
*/
void PORTD_PD4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD4_InterruptHandler = interruptHandler;
}

void PORTD_PD4_DefaultInterruptHandler(void)
{
    // add your PORTD_PD4 interrupt custom code
    // or set custom function using PORTD_PD4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_IO_PA3 at application runtime
*/
void PORTA_IO_PA3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_IO_PA3_InterruptHandler = interruptHandler;
}

void PORTA_IO_PA3_DefaultInterruptHandler(void)
{
    // add your PORTA_IO_PA3 interrupt custom code
    // or set custom function using PORTA_IO_PA3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA7 at application runtime
*/
void PORTA_PA7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA7_InterruptHandler = interruptHandler;
}

void PORTA_PA7_DefaultInterruptHandler(void)
{
    // add your PORTA_PA7 interrupt custom code
    // or set custom function using PORTA_PA7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF0 at application runtime
*/
void PORTF_PF0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF0_InterruptHandler = interruptHandler;
}

void PORTF_PF0_DefaultInterruptHandler(void)
{
    // add your PORTF_PF0 interrupt custom code
    // or set custom function using PORTF_PF0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_PE2 at application runtime
*/
void PORTE_PE2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_PE2_InterruptHandler = interruptHandler;
}

void PORTE_PE2_DefaultInterruptHandler(void)
{
    // add your PORTE_PE2 interrupt custom code
    // or set custom function using PORTE_PE2_SetInterruptHandler()
}
ISR(PORTB_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT2_bm)
    {
       PORTB_BTN_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

