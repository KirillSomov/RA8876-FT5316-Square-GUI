
#include "stm32f4xx.h"                  // Device header

uint16_t data = 0;


#include "CPU.h"
#include "GPIO.h"
#include "SPI.h"
#include "I2C.h"
#include "Timer.h"

#include "RA8876.h"
#include "FT5316.h"
#include "LCD_api.h"
#include "SGUI.h"


struct _ts_event ts_event = {0};
//extern const unsigned char image_foggy_forest_landscape_small[];


void btnAct1(void)
{
  LCD_drawFilledCircle(200, 300, 100, Red);
}

void btnAct2(void)
{
  LCD_drawFilledCircle(200, 300, 100, White);
}


int main(void)
{
  CPU_init();
  GPIO_setup();
  TIM6_DAC_init();
  SPIxInit(SPI3, 0, 0); //~13 MHz
   
  I2C1_init();
  //EXTI_init();
  Touch_init();
  LCD_init();
  LCD_setPage(PAGE0_START_ADDR);
  LCD_cleanCurrentPage(0xFFFF);
  delay_ms(500);

  GUI_pagesStorageInit();
  SGUI_createLabel(0, 100, 100, 150, 150, 10, Red, Blue, 0, 0, 0, 0, 0);
  SGUI_createButton(0, 400, 200, 500, 300, 2, Yellow, Magenta, 0, 0, 0, 0, 0, 1000, btnAct1);
  SGUI_createButton(0, 600, 200, 700, 300, 2, Magenta, Yellow, 0, 0, 0, 0, 0, 5000, btnAct2);
  SGUI_setPage(0);

  while(1)
  {
    Touch_handler();
    SGUI_sync(10);
    SGUI_handler();
    delay_ms(10);
  }
}
