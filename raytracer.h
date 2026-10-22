// ----- DEFINES ----- //
#define SCREEN_COLS             80
#define SCREEN_ROWS             20

// ----- TYPE DEFINES ----- //
typedef float vec4_t[4];

// ----- GLOBAL VARIABLES ----- //
char displayBuffer[(SCREEN_COLS + 2 + 2) * 
    (SCREEN_ROWS + 2) + 1] = { 0 };

// ----- PROTOTYPES ----- //

/*  @name   getOffset
 *  @desc   Given x,y convert coordinates to a screen offset for accessing
 *          the display buffer
 *  @param  uint8_t x   -- x coordinate
 *  @param  uint8_t y   -- y coordinate
 *  @return int
 */
int getOffset(uint8_t x, uint8_t y);

/*  @name   formatScreen
 *  @desc   Add box drawing characters to illustrate screen border as
 *          well as guarantee carriage returns/line feeds with terminator
 *  @param  void
 *  @return void
 */
void formatScreen(void);

/*  @name   writePixel
 *  @desc   Change a "pixel" at an x,y location in accordance with a given
 *          brightness.
 *  @param  uint8_t x           -- x coordinate
 *  @param  uint8_t y           -- y coordinate
 *  @param  uint8_t luminance   -- brightness
 *  @return void
 */
void writePixel(uint8_t x, uint8_t y, uint8_t luminance);

/*  @name   showScreen
 *  @desc   Display the screen
 *  @param  void
 *  @return void
 */
void showScreen(void);

/*  @name   vec4_scalar
 *  @desc   v *= scalar
 *  @param  vec4_t v        -- vector
 *  @param  float scalar    -- scalar
 *  @return void
 */
void vec4_scalar(vec4_t v, float scalar);

/*  @name   vec4_add
 *  @desc   a += b
 *  @param  vec4_t a    -- vector a
 *  @param  vec4_t b    -- vector b
 *  @return void
 */
void vec4_add(vec4_t a, vec4_t b);

/*  @name   vec4_sub
 *  @desc   a -= b
 *  @param  vec4_t a    -- vector a
 *  @param  vec4_t b    -- vector b
 *  @return void
 */
void vec4_sub(vec4_t a, vec4_t b);

/*  @name   vec4_dot
 *  @desc   a dot b
 *  @param  vec4_t a    -- vector a
 *  @param  vec4_t b    -- vector b
 *  @return float
 */
float vec4_dot(vec4_t a, vec4_t b);
