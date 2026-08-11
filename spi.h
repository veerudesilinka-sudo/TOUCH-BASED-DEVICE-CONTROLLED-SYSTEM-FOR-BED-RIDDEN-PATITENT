#include "types.h"
void Init_SPI(void);
u8 spi(u8 sDat);
void WriteEnable(void);
void WriteDisable(void);
void spi_eeprom_bytewrite(u16 wBuffAddr,u8 *p,u16 nbytes);
u8* spi_eeprom_byteread(u16 rBuffAddr,u8 *p,u16 nbytes);
