#  :lock: Electronic lock with tft diplay :unlock:

## :clipboard: Description
### What is it?
This is a application with nextion tft display.

Simulate a electronic lock with a 6 numbers password

### How this work?

the program is divided in four pages.
if you touch in first page (page0), this calls the second (page1).
In page1 you can return to page0 or try a password,
    -   if to password is correct the program calls the page2, active the relay for 5 seconds end return to the page0
    -   else if to calls the page3 end return to the page0 in five seconds.
## :computer: Deploy

- [Code](https://github.com/)

## :warning: Prerequisites
- Arduino
- Nextion display (in this example model NX8048T050)
- Relay model 5Vcc
- [Nextion official library for arduino](https://github.com/itead/ITEADLIB_Arduino_Nextion)


A subtle modification in NexConfig.h

    add '//' in line  #define DEBUG_SERIAL_ENABLE 
    modify the "nexSerial Serial2" for "nexSerial Serial" 
![Modify](\pic\modify.png)

## :arrow_forward: How to change the password?

Modify the passorwd numbers.

    char password[6] = {'1', '2', '3', '4', '5', '6'}; 

for exemple, password 342342

    char password[6] = {'3', '4', '2', '3', '4', '2'}; 
