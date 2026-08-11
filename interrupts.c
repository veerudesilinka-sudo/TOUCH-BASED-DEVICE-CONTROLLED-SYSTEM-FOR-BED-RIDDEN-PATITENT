#include<lpc21xx.h>
#include "types.h"
#include "SPI.h"
#include "define.h"
char str[25];
char x[10],y[10],z[10];
char ch,dummy;
unsigned int i=0,r_flag=0;
u8 keyvalue;
u8 entered_pass[5];
u8 stored_pass[6];
u8 pass1[5];
u8 pass2[5];
/* EINT3 ISR */
void eint3_isr(void)__irq
{
     	int i,ch;
        u8 key;
        CmdLCD(0x01);

        CmdLCD(0x80);
        StrLCD("ENTER CUR PASSWORD");

        CmdLCD(0xC0);
	   i=0;
       while(1)
		{
                key = KeyScan();
				if(key==10)


				{
				if(i>=0)
				{
				i--;
				entered_pass[i]='\0';
				  CmdLCD(0xC0+i);
				  CharLCD(' ');
				   CmdLCD(0xC0+i);
				   }
				   }
				   else if(key==16)
				   {
				   if(i==4)
				   break;
				   }
				   else
				   {
				   if(i<4)
				   {
                entered_pass[i] = key;
                CharLCD('*');
				i++;
				}
				}
		 }
        entered_pass[4] = '\0';
		EEPROM_Read_String(stored_pass);
		while(1)
		{
		ReadPassword();
		if(!ValidatePassword())
		{
		               CmdLCD(0x01);

                        CmdLCD(0x80);

                        StrLCD("WRONG PASS");
						delay_s(1);
						break;
		}

		               CmdLCD(0x01);

                        CmdLCD(0x80);

                        StrLCD("NEW PASSWORD");

                        CmdLCD(0xC0);
		i=0;
        while(1)
		{
                key = KeyScan();
				if(key==10)
				{
				if(i>=0)
				{
				i--;
				pass1[i]='\0';
				  CmdLCD(0xC0+i);
				  CharLCD(' ');
				   CmdLCD(0xC0+i);
				   }
				   }
				   else if(key==16)
				   {
				   if(i==4)
				   break;
				   }
				   else
				   {
				   if(i<4)
				   {
                pass1[i] = key;
                CharLCD('*');
				i++;
				}
				}
		 }
        pass1[4] = '\0';
                        delay_ms(1000);

                        CmdLCD(0x01);

                        CmdLCD(0x80);

                        StrLCD("CONFIRM PASS");

                        CmdLCD(0xC0);
		i=0;
        while(1)
		{
                key = KeyScan();
				if(key==10)
				{
				if(i>=0)
				{
				i--;
				 pass2[i]='\0';
				  CmdLCD(0xC0+i);
				  CharLCD(' ');
				   CmdLCD(0xC0+i);
				   }
				   }
				   else if(key==16)
				   {
				   if(i==4)
				   break;
				   }
				   else
				   {
				   if(i<4)
				   {
                pass2[i] = key;
                CharLCD('*');
				i++;
				}
				}
		 }
       pass2[4] = '\0';
	                  
                        if(strcmp(pass1,pass2)==0)
                        {
                                strcpy(stored_pass,pass1);

                                EEPROM_Write_String(stored_pass);
								 CmdLCD(0x01);
								 delay_ms(5);
                                 CmdLCD(0x80);

                                StrLCD("PASSWORD");

                                CmdLCD(0xC0);

                                StrLCD("UPDATED");
								delay_s(1);
								CmdLCD(0x01);
						  CmdLCD(0x80);
						  StrLCD("TOUCH SCREEN:EN/DIS");
						  CmdLCD(0xC0);
						  StrLCD("DEVICE1:ON/OFF");
						  CmdLCD(0x94);
						  StrLCD("DEVICE2:ON/OFF");
						  CmdLCD(0xD4);	 
						  StrLCD("DEVICE3:ON/OFF");
						  break;
                        }
                        else
                        { 
						         CmdLCD(0x01);
                                CmdLCD(0x80);
                                StrLCD("NOT MATCHED");
								delay_s(1);
								continue;
                        }
						}
        SCLRBIT(EXTINT,3);
        VICVectAddr=0;
		}
/* Enable EINT3*/
void Enable_EINT3(void)
{
        cfgportpinfunc(0,20,3);
        SSETBIT(VICIntEnable,17);
        VICVectCntl1=0x20|17;
        VICVectAddr1=(unsigned)eint3_isr;
        SSETBIT(EXTMODE,3);
        //SCLRBIT(EXTPOLAR,3);
}
void UART0_isr(void) __irq
{
         
        if(U0IIR & 0x04)
        {
                ch = U0RBR;

                if(ch != '\r')
                {
        
                                str[i++] = ch;                     
                }
				else
                        {
                                str[i] = '\0';
                                i=0;
                                r_flag=1;
                        }
        }
	   else
        dummy = U0IIR;
        VICVectAddr = 0;
}

/* UART0 Init */
void InitUART0(void)
{
        PINSEL0 = 0x00000005;

        U0LCR = 0x83;
        U0DLL = 97;
        U0DLM = 0x00;
        U0LCR = 0x03;

        U0IER = 0x01;

        VICIntSelect = 0x00;
        VICVectCntl0 = 0x20 | 6;
        VICVectAddr0 = (unsigned)UART0_isr;
        VICIntEnable = (1<<6);
}
