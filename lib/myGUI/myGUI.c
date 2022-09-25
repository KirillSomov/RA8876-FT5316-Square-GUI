
#include "myGUI.h"
#include "LCD_api.h"


SGUI_pageStorageCreate(0, 2, 3, 1);
SGUI_pageStorageCreate(1, 2, 3, 0);
SGUI_pagesStorageCreate(2);
SGUI_guiStorageCreate();


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  GUI.pages[1] = &page_1;
}


static void btnAct1(void);
static void btnAct2(void);

static void btnGoToPage0(void);
static void btnGoToPage1(void);


extern const unsigned char image_deb_8bpp;


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(0xBCDB);
  SGUI_createLabel(0, 100, 100, 150, 150, 0, 0, 10, Red, Blue, 0, 0, 0, 0, 0);
  SGUI_createButton(0, 400, 200, 500, 300, 0, 0, 2, Yellow, Magenta, 0, 0, 0, 0, 0, 1000, btnAct1);
  SGUI_createButton(0, 600, 200, 700, 300, 10, 10, 5, Magenta, Yellow, 0, 0, 0, 0, 0, 5000, btnAct2);
  SGUI_createButton(0, 850, 50, 900, 100, 0, 0, 2, Red, Grey, 0, 0, 0, 0, 0, 100, btnGoToPage1);
  SGUI_createPicture(0, &image_deb_8bpp, 50, 50, 400, 422, 8, 8, 4, 0x4BC6);
  SGUI_drawFrame(800, 400, 900, 500,
                 5, 5,
                 5, 0);
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


void myGUI_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
  page_1_init();
  SGUI_showPage(0);
}
