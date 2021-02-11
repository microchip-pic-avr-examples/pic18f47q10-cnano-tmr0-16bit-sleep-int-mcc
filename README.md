[![MCHP](images/microchip.png)](https://www.microchip.com)

# PIC18F47Q10 Using TMR0 in 16-bit Mode with Periodic Interrupt


## Objective
This repository contains an example of MCC-generated source code for TMR0 as described in [*TB3285 - Getting Started with Timers/Counters on PIC18*](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1003329) document from Microchip.

<br>This example describes how to configure TMR0 in 16-bit mode and generate an overflow interrupt every ten seconds, using LFINTOSC as clock source.
<br>TMR0 will run while the microcontroller is in Sleep mode.
<br>A GPIO pin (the development board’s on-board LED) will be configured as output and when the interrupt occurs, the microcontroller is woken up, the LED is lit for 100 ms and then the microcontroller is put back in Sleep mode.
<br>The code was generated using MPLAB® Code Configurator.

## Related Documentation
- [TB3285 - Getting Started with Timers/Counters on PIC18](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1003329)
- [PIC18-Q10 Product Family Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family)
- [PIC18F47Q10 Data Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40002043D.pdf)
- [PIC18F47Q10 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=pic18f47q10-cnano&type=&language=)

## Software Used
- MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 2.10 or newer [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
- MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs 1.79.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- Microchip PIC18F-Q Series Device Support 1.3.89 or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/)

## Hardware Used
- PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)


## Setup
The PIC18F47Q10 Curiosity Nano Development Board is used as the test platform.

<br><img src="images/PIC18F47Q10_CNANO.png" width="600">

The following configurations must be made for this project:
- Clock
  - Oscillator Select: HFINTOSC
  - HF Internal Clock: 1 MHz
  - Clock Divider: 1
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
- Low-voltage Programming: enabled

|Pin           | Configuration      |
| :----------: | :----------------: |
|RE0 (LED0)    | Digital Output     |

## Operation
1. Connect the board to the PC.

2. Open the *pic18f47q10-cnano-tmr0-16bit-sleep-int-mcc.X* project in MPLAB® X IDE.

3. Set *pic18f47q10-cnano-tmr0-16bit-sleep-int-mcc* project as main project. Right click on the project in the *Projects* tab and click *Set as Main Project*:
<br><img src="images/TMR0-16bit-sleep-int-mcc-main-project.png" width="600">

4. Select the *PIC18F47Q10 Curiosity Nano* in the *Hardware Tool* section of the project settings:
  - Right click on the project and click *Properties*;
  - Select the *PIC18F47Q10 Curiosity Nano* (click on the SN) in the *Hardware Tool* tab and then click *OK*:
<br><img src="images/TMR0-16bit-sleep-int-mcc-tool-settings.png" width="600">


5. Program the project to the board: right click on the project and click *Make and Program Device*:
<br><img src="images/TMR0-16bit-sleep-int-mcc-program.png" width="600">


Demo:
<br><img src="images/TMR0_16bit_sleep_int.gif" alt="Hardware Setup"/>

## Summary

This project is an illustration for a basic use case based around TMR0.
