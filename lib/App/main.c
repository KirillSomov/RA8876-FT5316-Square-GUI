
#include "stm32f4xx.h"                  // Device header
#include "CPU.h"
#include "GPIO.h"
#include "SPI.h"
#include "I2C.h"
#include "Timer.h"
#include "LCD_api.h"
#include "myGUI.h"


int main(void)
{
  CPU_init();
  GPIO_setup();
  TIM10_init();
  SPIxInit(SPI3, 0, 0); //~13 MHz
   
  I2C1_init();
  //EXTI_init();
  Touch_init();
  LCD_init();
  LCD_setPage(PAGE0_START_ADDR);
  LCD_cleanCurrentPage(0xFFFF);
  delay_ms(500);

  myGUI_init();

  while(1)
  {
    Touch_handler();
    SGUI_sync(1);
    SGUI_handler();
    delay_ms(1);
  }
}
