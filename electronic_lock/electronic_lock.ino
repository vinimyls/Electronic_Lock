#include "Nextion.h"

/************************ Nextion components ****************/
//page 0
NexButton btnNext         = NexButton(0, 1, "btn_next");    //button "go to page1"
NexPage page0             = NexPage(0, 0, "page0");         //

//page 1
NexButton btnN0           = NexButton(1,  2, "b0");         //button number 0
NexButton btnN1           = NexButton(1,  3, "b1");         //button number 1
NexButton btnN2           = NexButton(1,  4, "b2");         //button number 2
NexButton btnN3           = NexButton(1,  5, "b3");         //button number 3
NexButton btnN4           = NexButton(1,  6, "b4");         //button number 4
NexButton btnN5           = NexButton(1,  7, "b5");         //button number 5
NexButton btnN6           = NexButton(1,  8, "b6");         //button number 6
NexButton btnN7           = NexButton(1,  9, "b7");         //button number 7
NexButton btnN8           = NexButton(1, 10, "b8");         //button number 8
NexButton btnN9           = NexButton(1, 11, "b9");         //button number 9
NexButton btnCancel       = NexButton(1, 12, "btn_cancel"); //button "return to page 0"
NexPage page1             = NexPage(1, 0, "page1");          // page 1

// page 2
NexPage page2             = NexPage(2, 0, "page2");          
// page 3
NexPage page3             = NexPage(3, 0, "page3");       

// This array contains the objects there are touch interactive
NexTouch *nex_listen_list[] =
{
  &btnNext,
  &btnN0,
  &btnN1,
  &btnN2,
  &btnN3,
  &btnN4,
  &btnN5,
  &btnN6,
  &btnN7,
  &btnN8,
  &btnN9,
  &btnCancel,
  NULL
};
/*****************    Variables     ****************/
bool isCorrect;                                    // for password verification
bool back;                                         // for return to page 0
int digit;                                         //
char buffer[100] = {0};                            // buffer from serial port
char password[6] = {'1', '2', '3', '4', '5', '6'}; // password correct 
char passwordTry[6] = {0};                         //
//time control variables                           //
long previousMillis = 0;                           //
const int maxTime = 3000;                          //
/***************************************************/

void setup() 
{
  Serial.begin(9600);
  nexInit();                                       //serial nextion inicialize
  btnNext.attachPop(btnNextPopCallback, &btnNext); //callback for release events from nextion buttons
  btnN0.attachPop(btnN0PopCallback, &btnN0);
  btnN1.attachPop(btnN1PopCallback, &btnN1);
  btnN2.attachPop(btnN2PopCallback, &btnN2);
  btnN3.attachPop(btnN3PopCallback, &btnN3);
  btnN4.attachPop(btnN4PopCallback, &btnN4);
  btnN5.attachPop(btnN5PopCallback, &btnN5);
  btnN6.attachPop(btnN6PopCallback, &btnN6);
  btnN7.attachPop(btnN7PopCallback, &btnN7);
  btnN8.attachPop(btnN9PopCallback, &btnN8);
  btnN9.attachPop(btnN9PopCallback, &btnN9);
  btnCancel.attachPop(btnCancelPopCallback, &btnCancel);
}

void loop() {
  nexLoop(nex_listen_list);
  // if return to page0 is active, this delay is implement. //
  if (digit >= 6)
  {
    verifyPassword();
  }
  if (back)
  {
    if (millis() - previousMillis >= maxTime)
    {
      page0.show(); 
      back = false;                           
      digit = 0;
    }
  }
}


/***********  Vefiry password   ********/

void verifyPassword(void)
{
  isCorrect = true;
  for (digit = 0; digit < 6; digit++)
  {
    if (passwordTry[digit] != password[digit])
    {
      isCorrect = false;
    }
  }
  if (isCorrect)
  {
    page2.show();
  }
  else
  {
    page3.show();
  }
  back = true;
  previousMillis = millis();
}

/***********  CALLBACKS   ********/

void btnNextPopCallback(void *ptr)
{
  page1.show();
}
void btnN0PopCallback(void *ptr)
{
  passwordTry[digit] = '0';
  digit++;
}
void btnN1PopCallback(void *ptr)
{
  passwordTry[digit] = '1';
  digit++;
}
void btnN2PopCallback(void *ptr)
{
  passwordTry[digit] = '2';
  digit++;
}
void btnN3PopCallback(void *ptr)
{
  passwordTry[digit] = '3';
  digit++;
} 
void btnN4PopCallback(void *ptr)
{
  passwordTry[digit] = '4';
  digit++;
}
void btnN5PopCallback(void *ptr)
{
  passwordTry[digit] = '5';
  digit++;
}
void btnN6PopCallback(void *ptr)
{
  passwordTry[digit] = '6';
  digit++;
}
void btnN7PopCallback(void *ptr)
{
  passwordTry[digit] = '7';
  digit++;
}
void btnN8PopCallback(void *ptr)
{
  passwordTry[digit] = '8';
  digit++;
}
void btnN9PopCallback(void *ptr)
{
  passwordTry[digit] = '9';
  digit++;
}
void btnCancelPopCallback(void *ptr)
{
  digit = 0;
  page0.show();
}
