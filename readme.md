<div id="readme" class="Box-body readme blob js-code-block-container">
 <article class="markdown-body entry-content p-3 p-md-6" itemprop="text"><p><a href="https://www.microchip.com" rel="nofollow"><img src="images/MicrochipLogo.png" alt="MCHP" style="max-width:100%;"></a></p>

# PIC18F47Q10 Using TMR0 in 16-bit Mode with Periodic Interrupt:


## Objective:
This example describes how to configure TMR0 in 16-bit mode and generate an overflow interrupt every ten seconds,
using LFINTOSC as clock source. TMR0 will run while the microcontroller is in Sleep mode. A GPIO pin (the
development board’s on-board LED) will be configured as output and when the interrupt occurs, the microcontroller is
woken up, the LED is lit for 100 ms and then the microcontroller is put back in Sleep mode. The code was generated using MPLAB Code Configurator.

## Resources:
- Technical Brief Link [(linkTBD)](http://www.microchip.com/)
- MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 2.10 or newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
- MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- MPLAB® Code Configurator PIC10/PIC12/PIC16/PIC18 library v1.79.0 [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)
- [PIC18F47Q10 datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40002043D.pdf) for more information or specifications.

## Hardware Configuration:

The PIC18F47Q10 Curiosity Nano Development Board [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029) is used as the test platform.

The following configurations must be made for this project:
- Clock
	– Oscillator Select: HFINTOSC
	– HF Internal Clock: 1 MHz
	– Clock Divider: 1
- Port
	- RE0 (LED0) pin - Configured as digital output
- TMR0
	- TMR0 Enabled
	- Clock Prescaler: 1:32
	- Postscaler: 1:1
	- Timer mode: 16-bit
	- Clock Source: LFINTOSC
	- Synchronization: disabled
	- Timer period: 10 seconds
	- Timer interrupt: enabled
- Watchdog Timer: disabled

## Demo:
Run the code, LED0 will light up for 100 ms, once every 10 seconds.

<img src="images/TMR0_16bit_sleep_int.gif" alt="Hardware Setup"/>