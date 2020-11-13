#ifndef _FLASH_H
#define _FLASH_H

#include <EEPROM.h>
#include <flash_stm32.h>



void STM32_FlashRead(uint32 addreaa, uint8_t *data, uint32_t len);
void STM32_FlashWrite(uint32 addreaa,uint8_t *data, uint32_t len);
#endif
