#include "SPI_defines.h"
#include <lpc21xx.h>
#include "pinconnectblock.h"
#include "delay.h"
void Init_SPI(void)
{
   //cfg p0.4 pin as SCK pin using PINSEL0
   cfgportpinfunc(0,4,1);
   //cfg p0.5 pin as MOSI pin using PINSEL0
   cfgportpinfunc(0,5,1);
   //cfg p0.6 pin as MISO pin using PINSEL0
	cfgportpinfunc(0,6,1);
   //make p0.7(cs) as high using IOSET0/IOPIN0
  IOSET0=1<<CS;
   //cfg p0.7 as gpio output pin using IODIR0
   IODIR0=1<<CS;
   //cfg spi clock speed using S0SPCCR
  S0SPCCR=LOADVAL;
   //cfg spi peripheral for Master Mode & Mode3
   S0SPCR=1<<MSTR|3<<CPHA;
}



u8 spi(u8 sDat)
{
   //load sDat into S0SPDR
   S0SPDR=sDat;
   // wait for transmission to complete 
   //using S0SPSR and   monitoring SPIF bit
  while(((S0SPSR>>SPIF)&1)==0);
   // return read data from S0SPDR;
  return S0SPDR;
}

void WriteEnable(void)
{
  //make chip select low
  IOCLR0=1<<CS;
  //issue WREN via spi tranfer
  spi(WREN);
 //make chip select high
 IOSET0=1<<CS;
}

void WriteDisable(void)
{
  //make chip select low
		IOCLR0=1<<CS;
   //issue WRDI via spi transfer
			spi(WRDI);
  //make chip select high
		IOSET0=1<<CS;
}

void spi_eeprom_bytewrite(u16 wBuffAddr,u8 *p,u16 nbytes)
{
	u16 i;
   //Enable Write Enable Latch
		WriteEnable();
   //make chip select low
 IOCLR0=1<<CS;
   //issue WRITE instruction via spi transfer
  spi(WRITE);
   //msbyte of 16-bit address loc via spi transfer
  spi(wBuffAddr>>8);
	
  //lsbyte of 16-bit address loc via spi transfer
	spi(wBuffAddr);
 for(i=0;i<nbytes;i++)
 {
	spi(p[i]);
 }
  //make chip select high
  IOSET0=1<<CS;
 //delay for internal write cycle
 delay_ms(5);
 //Disable Write Enable Latch
  WriteDisable();
}


u8* spi_eeprom_byteread(u16 rBuffAddr,u8 *p,u16 nbytes)
{
  u16 i;
  //make chip select low
  IOCLR0=1<<CS;
  //issue READ instruction
    spi(READ);
 //msbyte of 16-bit address loc to be read via spi
 spi(rBuffAddr>>8);
  //lsbyte of 16-bit address loc to be read via spi
   spi(rBuffAddr);
 for(i=0;i<nbytes;i++)
 {
  p[i]=spi(0x00);
 }
  //make chip select high
 IOSET0=1<<CS;   
}  
return p;
