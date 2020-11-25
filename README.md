#  :lock: Electronic Lock With TFT Nextion Diplay :unlock:

## :clipboard: Description
### What is it?
This is an application with nextion tft display.

Simulate an electronic lock with 6 numbers password

Correct password:
- ![Correct](https://github.com/vinimyls/Electronic_Lock/blob/main/pic/correct.gif)

Incorrect password:
- ![Incorrect](https://github.com/vinimyls/Electronic_Lock/blob/main/pic/incorrect.gif)

### How this work?

The program is divided in four pages.

if you touch in first page (page0), this calls the second (page1).

In page1 you can return to page0 or try a password.

    -   if to password is correct the program calls the page2, active the relay for 5 seconds end return to the page0.
    
    -   else if to calls the page3 end return to the page0 in five seconds.
## :computer: Code

- [Code](https://github.com/vinimyls/Electronic_Lock/blob/main/electronic_lock/electronic_lock.ino)
- [HMI file for nextion editor](https://github.com/vinimyls/Electronic_Lock/blob/main/Electronic_lock.HMI)
## :electric_plug: Hardware
- ![Diagram](https://github.com/vinimyls/Electronic_Lock/blob/main/pic/diagram.png)
## :warning: Prerequisites
- Arduino
- Nextion display (in this example model NX8048T050)
- Relay model 5Vcc
- [Nextion official library for arduino](https://github.com/itead/ITEADLIB_Arduino_Nextion)
- [Nextion Editor for HMI](https://nextion.tech/nextion-editor/)


A subtle modification in NexConfig.h

    add '//' in line  #define DEBUG_SERIAL_ENABLE 
    modify the "nexSerial Serial2" for "nexSerial Serial" 
![Modify](https://github.com/vinimyls/Electronic_Lock/blob/main/pic/modify.png)

## :arrow_forward: How to change the password?

Modify the passorwd numbers.

    char password[6] = {'1', '2', '3', '4', '5', '6'}; 

for exemple, password 342342

    char password[6] = {'3', '4', '2', '3', '4', '2'}; 
