#include<lpc21xx.h>
#include "lcd.h"
#include "delay.h"
#include "define.h"
int touchenable=0;
int touchflag1=0; 
int touchflag2=0;
int touchflag3=0;
int touchflag4=0;
void device1(void)
{
  touchflag1++;
 if(touchflag1==1)
 {
  CmdLCD(0xC0);
  StrLCD("DEVICE1:ON    ");
  	IOSET1=LED1;
	if(touchflag2)										 
	{
	IOSET1=LED2;
	}
	}
	else if(touchflag1==2) 
	{
     CmdLCD(0xC0);
     StrLCD("DEVICE1:OFF   ");
	IOCLR1=LED1;
	if(touchflag2)
	{
	IOSET1=LED2;
	}
	touchflag1=0;
	}
}
void device2(void)
 {
 touchflag2++;
if(touchflag2==1)
 {
  CmdLCD(0x94);
  StrLCD("DEVICE2:ON    ");
  IOSET1=LED2;
  if(touchflag1)
	{
     IOSET1=LED1;
	}
	}
  else if(touchflag2==2)
	{
      CmdLCD(0x94);
      StrLCD("DEVICE2:OFF    ");
	  IOCLR1=LED2;
   	if(touchflag1)
	{
	IOSET1=LED1;
	}
	touchflag2=0;
	}
}
void device3(void)
{
 if(touchflag3==0)
{
 touchflag3=1;
 CmdLCD(0xD4);
 StrLCD("DEVICE3:ON     ");
IOSET0=BUZZER;
delay_s(2);
IOCLR0=BUZZER;
touchflag3=0;
CmdLCD(0xD4);
StrLCD("DEVICE3:OFF   ");
} 
}
void disable(void)
{
if(touchflag1==1)
 {
  CmdLCD(0xC0);
  StrLCD("DEVICE1:ON     ");
  IOSET1=LED1;
  if(touchflag2)										 
 {
  IOSET1=LED2;
  }
  }
else if(touchflag1==2) 
 {
 CmdLCD(0xC0);
 StrLCD("DEVICE1:OFF    ");
 IOCLR1=LED1;
 if(touchflag2)
 {
 IOSET1=LED2;
  }
touchflag1=0;
}
if(touchflag2==1)
{
CmdLCD(0x94);
StrLCD("DEVICE2:ON    ");
IOSET1=LED2;
if(touchflag1)
{
IOSET1=LED1;
}
}
else if(touchflag2==2)
{
CmdLCD(0x94);
StrLCD("DEVICE2:OFF    ");
IOCLR1=LED2;
if(touchflag1)
{
IOSET1=LED1;
}
touchflag2=0;
}
if(touchflag3==0)
{
 CmdLCD(0xD4);
 touchflag3=0;
 CmdLCD(0xD4);
StrLCD("DEVICE3:OFF    ");
}
}


