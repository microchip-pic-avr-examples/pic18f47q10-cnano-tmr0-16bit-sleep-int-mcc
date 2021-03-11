/**
  TMR0 Generated Driver File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    tmr0.c
 
  @Summary
    This is the generated driver implementation file for the TMR0 driver
 
  @Description
    This source file provides APIs for driver for TMR0.
    Generation Information :
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLAB X v5.45
*/

/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#include <xc.h>
#include "../tmr0.h"

volatile uint16_t timerTMR0ReloadVal16bit;

const struct TMR_INTERFACE Timer0 = {
    .Initialize = Timer0_Initialize,
    .Start = Timer0_Start,
    .Stop = Timer0_Stop,
    .PeriodCountSet = Timer0_Write,
    .TimeoutCallbackRegister = Timer0_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*Timer0_OverflowCallback)(void);
static void Timer0_DefaultOverflowCallback(void);

void Timer0_Initialize(void)
{
    //TMR0H 218; 
    TMR0H = 0xDA;

    //TMR0L 41; 
    TMR0L = 0x29;

    //T0CS LFINTOSC; T0CKPS 1:32; T0ASYNC not_synchronised; 
    T0CON1 = 0x95;

    //Load TMRTMR0 value to the 16-bit reload variable
    timerTMR0ReloadVal16bit = ((uint16_t)TMR0H << 8) | TMR0L;

    //Set default callback for TMR0 overflow interrupt
    Timer0_OverflowCallbackRegister(Timer0_DefaultOverflowCallback);

    //Clear Interrupt flag before enabling the interrupt
    PIR0bits.TMR0IF = 0;
	
    //Enable TMR0 interrupt.
    PIE0bits.TMR0IE = 1;
	
    //T0OUTPS 1:1; T0EN enabled; T016BIT 16-bit; 
    T0CON0 = 0x90;
}

void Timer0_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void Timer0_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint16_t Timer0_Read(void)
{
    uint16_t readVal;
    uint8_t readValLow;
    uint8_t readValHigh;

    readValLow  = TMR0L;
    readValHigh = TMR0H;
    readVal  = ((uint16_t)readValHigh << 8) + readValLow;

    return readVal;
}

void Timer0_Write(size_t timerVal)
{
    TMR0H = timerVal >> 8;
    TMR0L = (uint8_t) timerVal;
}

void Timer0_Reload(void)
{
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;
}

void Timer0_OverflowISR(void)
{
    //Clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    //Write to the TimerTMR0 register
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;

    if(Timer0_OverflowCallback)
    {
        Timer0_OverflowCallback();
    }
}

void Timer0_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer0_OverflowCallback = CallbackHandler;
}

static void Timer0_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use Timer0_OverflowCallbackRegister function to use Custom ISR
}

