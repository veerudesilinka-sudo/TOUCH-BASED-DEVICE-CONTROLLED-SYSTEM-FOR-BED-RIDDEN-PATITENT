#include<lpc21xx.h>
#include "types.h"
#include "SPI.h"
#include "delay.h"
 extern u8 keyvalue;
extern u8 entered_pass[5];
 extern u8 stored_pass[6];
extern u8 pass1[5];
extern u8 pass2[5];
void ReadPassword(void)
{
 spi_eeprom_byteread(0x0000,stored_pass,4);
        stored_pass[5] = '\0';
}
void GetPassword(void)
{
        int i,ch;
        u8 key;

        CmdLCD(0x01);

        CmdLCD(0x80);
        StrLCD("ENTER PASSWORD");

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

}

u8 ValidatePassword(void)
{
        int i;

        for(i=0;i<4;i++)
        {
                if(entered_pass[i]!= stored_pass[i])
                {
                        return 0;
                }
        }
        return 1;
}					  

void StorePassword(void)
{
        u8 pass[4]={1,2,3,4};
        spi_eeprom_bytewrite(0x0000,pass,4);
}
/* Read password */
void EEPROM_Read_String(u8 *p)
{
        spi_eeprom_byteread(0x0000,p,4);

        p[4]='\0';
}

/* Write updated password */
void EEPROM_Write_String(u8 *p)
{
        spi_eeprom_bytewrite(0x0000,p,4);
}