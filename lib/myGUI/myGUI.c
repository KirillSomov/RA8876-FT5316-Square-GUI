
#include "myGUI.h"
#include "LCD_api.h"


SGUI_pageStorageCreate(0, 2, 2, 1, 0);
SGUI_pageStorageCreate(1, 2, 3, 0, 0);
SGUI_pageStorageCreate(2, 0, 2, 0, 1);
SGUI_pagesStorageCreate(3);
SGUI_guiStorageCreate();


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  GUI.pages[1] = &page_1;
  GUI.pages[2] = &page_2;
}


static void btnAct1(void);
static void btnAct2(void);

static void btnGoToPage0(void);
static void btnGoToPage1(void);
static void btnGoToPage2(void);
static void btnCanvasClear(void);
static void сanvasActStar(void);
static void сanvasActLine(void);


extern const unsigned char image_deb_8bpp;


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(0xBCDB);
  SGUI_createLabel(0, 100, 100, 150, 150, 0, 0, 10, Red, Blue, 0, 0, 0, 0, 0);
  SGUI_createButton(0, 850, 50, 900, 100, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnGoToPage1);
  SGUI_createButton(0, 910, 50, 960, 100, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnGoToPage2);
  SGUI_createPicture(0, &image_deb_8bpp, 50, 50, 400, 422, 8, 8, 4, 0x4BC6);
  SGUI_drawFrame(800, 400, 900, 500,
                 5, 5,
                 5, 0);
  //LCD_printString("HELLO\nWORLD", 800, 200, FONT_SIZE_16X32, 1, 1, Magenta, Black);
  SGUI_printString("one\ntw\nthree\nfour", 800, 150, FONT_SIZE_48, Magenta, Black);
  SGUI_printString("five", 800, 500, FONT_SIZE_48, Magenta, Black);
  SGUI_drawLine(500, 10, 500, 500, 10, Black);
  SGUI_drawLine(500, 10, 900, 500, 10, Black);
  SGUI_drawLine(900, 10, 500, 500, 10, Black);
  SGUI_drawPage(0);
}


static void page_1_init(void)
{
  SGUI_LinkPageToLcd(1, PAGE1_START_ADDR);
  SGUI_setPage(1);
  SGUI_clearPage(0xBCDB);
  SGUI_createLabel(1, 150, 150, 200, 200, 0, 0, 10, Blue, Red, 0, 0, 0, 0, 0);
  SGUI_createButton(1, 450, 250, 550, 350, 0, 0, 2, Black, Green, 0, 0, 0, 0, 0, 1000, btnAct1);
  SGUI_createButton(1, 650, 250, 750, 350, 0, 0, 2, Green, Grey, 0, 0, 0, 0, 0, 5000, btnAct2);
  SGUI_createButton(1, 850, 50, 900, 100, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnGoToPage0);
  SGUI_drawPage(1);
}


static void page_2_init(void)
{
  SGUI_LinkPageToLcd(2, PAGE2_START_ADDR);
  SGUI_setPage(2);
  SGUI_clearPage(0xBCDB);
  SGUI_createButton(2, 850, 50, 900, 100, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnGoToPage0);
  SGUI_createButton(2, 850, 200, 900, 250, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnCanvasClear);
  SGUI_createCanvas(2, 10, 10, 410, 410, 5, 5, 5, White, Green, 10, Red, сanvasActLine);
  SGUI_canvasSetPenWeight(2, 0, 5);
  SGUI_drawPage(2);
}


static void btnAct1(void)
{
  LCD_drawFilledCircle(200, 300, 100, Red);
}

static void btnAct2(void)
{
  LCD_drawFilledCircle(200, 300, 100, White);
}


static void btnGoToPage0(void)
{
  SGUI_showPage(0);
}

static void btnGoToPage1(void)
{
  SGUI_showPage(1);
}

static void btnGoToPage2(void)
{
  SGUI_showPage(2);
}


static void btnCanvasClear(void)
{
  SGUI_canvasClear(2, 0);
}


static void сanvasActStar(void)
{
  unsigned short x, y;
  SGUI_getSampleTouch(&x, &y);
  SGUI_printString("*", x, y, FONT_SIZE_48, -1, Black);
  SGUI_canvasIdle(2, 0, 200);
}

static void сanvasActLine(void)
{
  static bool init = false;
  static unsigned short x0 = 0xFFFF, y0 = 0xFFFF;
  unsigned short x1, y1;
  SGUI_getSampleTouch(&x1, &y1);
  if(((x1-x0) < 10) && ((y1-y0) < 10))
  {
    SGUI_drawLine(x0, y0, x1, y1, 5, Red);
  }
  x0 = x1;
  y0 = y1;
}


void myGUI_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
  page_1_init();
  page_2_init();
  SGUI_showPage(0);
}
