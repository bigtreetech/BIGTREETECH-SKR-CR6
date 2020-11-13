#include "Flash.h"

void STM32_FlashRead(uint32 addreaa, uint8_t *data, uint32_t len)
{
  uint32_t i = 0;
  for(i = 0; i < len; i++)
  {
    data[i] = *(volatile uint8_t*)(addreaa + i);
  }
}

void STM32_FlashWrite(uint32 addreaa,uint8_t *data, uint32_t len)
{
  uint32_t i = 0;
  FLASH_Unlock();
  FLASH_ErasePage(addreaa);
  for(i = 0; i < len; i += 2)
  {
    uint16_t data16 = data[i] | (data[min(i+1, len-1)] << 8);  //stm32f10x needs to write at least 16 bits at a time
    FLASH_ProgramHalfWord(addreaa + i, data16);
  }
  FLASH_Lock();
}