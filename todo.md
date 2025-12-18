# Todo list
## Stage 1a
 - Put together hardware
 - Code software to interface w/ hardware
## Stage 1b
- Test and deploy model
- Build pipeline?
## Stage 2a
- Make Rev 1 of PCB
Complete schematics for the following:
    - MCU
    - ~~DISPLAY_TFT~~
    - ~~RTC_DS3234~~
    - ~~CAMERA~~    
    - ~~LoRA~~
    - ~~USB_C~~
    - ~~MCP78371~~

- Check if GPIO is default High impedance from the registers

Find out if below is possible:
| Goal | Best Option | 
| :------: | :---: | 
| Want to run Arduino sketches | Flash Arduino Nano BLE bootloader |
| Want to run Python scripts | Use Adafruit UF2 bootloader + CircuitPython| 
| Want full control / Zephyr / SDK | Use Nordic’s SDK + J-Link |
| Want both Arduino + MicroPython flexibility| Use Adafruit UF2 bootloader, supports both|

- learn to write over the bootloader, flash from scratch




## Stage 2b
- Design model housing