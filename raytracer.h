// ----- DEFINES ----- //
#define SCREEN_COLS             80
#define SCREEN_ROWS             20

// ----- GLOBAL VARIABLES ----- //
char displayBuffer[(SCREEN_COLS + 2 + 2) * 
    (SCREEN_ROWS + 2) + 1] = { 0 };

// ----- PROTOTYPES ----- //

/*  @name   getOffset
 *  @desc   Given x,y convert coordinates to a screen offset for accessing
 *          the display buffer
 *  @param  uint8_t x   -- x coordinate
 *  @param  uint8_t y   -- y coordinate
 */
int getOffset(uint8_t x, uint8_t y);

/*  @name   formatScreen
 *  @desc   Add box drawing characters to illustrate screen border as
 *          well as guarantee carriage returns/line feeds with terminator
 */
void formatScreen(void);

/*  @name   writePixel
 *  @desc   Change a "pixel" at an x,y location in accordance with a given
 *          brightness.
 *  @param  uint8_t x           -- x coordinate
 *  @param  uint8_t y           -- y coordinate
 *  @param  uint8_t luminance   -- brightness
 */
void writePixel(uint8_t x, uint8_t y, uint8_t luminance);

/*  @name   showScreen
 *  @desc   Display the screen
 */
void showScreen(void);
