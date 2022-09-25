
#include "SGUI_dataTransfer.h"
#include "LCD_api.h"


void SGUI_setLcdPage(unsigned long page)
{
  LCD_setPage(page);
}


void SGUI_showLcdPage(unsigned long page)
{
  LCD_showPage(page);
}


void SGUI_LCD_drawSquare(unsigned short x0, unsigned short y0,
                         unsigned short x1, unsigned short y1,
                         unsigned short rx, unsigned short ry,
                         unsigned short color)
{
  if((rx > 0) || (ry > 0))
  {
    LCD_drawCircleSquare(x0, y0, x1, y1, rx, ry, color);
  }
  else
  {
    LCD_drawSquare(x0, y0, x1, y1, color);
  }
}

void SGUI_LCD_drawFilledSquare(unsigned short x0, unsigned short y0,
                               unsigned short x1, unsigned short y1,
                               unsigned short rx, unsigned short ry,
                               unsigned short color)
{
  if((rx > 0) || (ry > 0))
  {
    LCD_drawFilledCircleSquare(x0, y0, x1, y1, rx, ry, color);
  }
  else
  {
    LCD_drawFilledSquare(x0, y0, x1, y1, color);
  }
}

void SGUI_LCD_drawPicture(const unsigned char* picture,
                          unsigned long page,
                          unsigned short x, unsigned short y,
                          unsigned short w, unsigned short h)
{
  LCD_drawBitmapPageBuf(picture, MODE_8BPP, PAGE9_START_ADDR, page, MODE_16BPP,
                        x, y, w, h);
}


void SGUI_LCD_printString(char* string,
                          unsigned short x, unsigned short y,
                          unsigned short size,
                          unsigned short backgroundColor, unsigned short textColor)
{
  switch(size)
  {
    case FONT_SIZE_24:
      LCD_printString(string, x, y,
                      FONT_SIZE_12X24, FONT_WIDTH_X1, FONT_HEIGHT_X1,
                      backgroundColor, textColor);
      break;

    case FONT_SIZE_48:
      LCD_printString(string, x, y,
                      FONT_SIZE_12X24, FONT_WIDTH_X2, FONT_HEIGHT_X2,
                      backgroundColor, textColor);
      break;

    default:
      break;
  }
}


bool SGUI_sampleTouch(unsigned short* x, unsigned short* y)
{
  return Touch_sampleTouch(x, y);

  // default
  return false;
}
