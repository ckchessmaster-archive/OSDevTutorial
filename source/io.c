#include "ioasm.h"

/* The I/O ports */
#define FB_COMMAND_PORT   0x3D4
#define FB_DATA_PORT      0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

/* The frame buffer colors */
#define FB_BLACK          0
#define FB_BLUE           1
#define FB_GREEN          2
#define FB_CYAN           3
#define FB_RED            4
#define FB_MAGENTA        5
#define FB_BROWN          6
#define FB_LIGHT_GREY     7
#define FB_DARK_GREY      8
#define FB_LIGHT_BLUE     9
#define FB_LIGHT_GREEN   10
#define FB_LIGHT_CYAN    11
#define FB_LIGHT_RED     12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN   14
#define FB_WHITE         15

// The framebuffer for writing to the screen
static char *fb = (char *) 0x000B8000;

// The current cursor position
static unsigned short cursorX = 0;
static unsigned short cursorY = 0;

/** convertPosToFB:
 * Convert x and y coordinates to framebuffer coordinates
 *
 * @param x The x position of the cursor
 * @param y The y position of the cursor
 */
static unsigned short convertPosToFB(unsigned short x, unsigned short y) {
  return (x + (80 * y));
}//end convertPosToFB

/** fb_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param x The new X position of the cursor
 * @param y The new Y position of the cursor
 */
static void fb_move_cursor(unsigned short x, unsigned short y) {
  // update position
  cursorX = x;
  cursorY = y;

  // Convert to framebuffer location (where 80 is the max width)
  unsigned short pos = convertPosToFB(x, y);

  // move the cursor
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT, pos & 0x00FF);
}// end fb_move_cursor

/** fb_write_cell:
 * Writes a character with the given foreground and background to position i
 * in the framebuffer.
 *
 * @param i The location in the framebuffer
 * @param c The character
 * @param fg The foreground color
 * @param bg The background color
 */
static void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned bg) {
  fb[i] = c;
  fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}//end fb_write_cell

/** fb_scrollUp:
 * Scroll the screen upwards so we can keep writing to the screen
 *
 */
static void fb_scrollUp() {
  // copy all memory upwards
  //for(int i = 0; i < 2 * (convertPosToFB(cursorX, cursorY)); i++) {
    //fb[i] = fb[i + 2];
  //}

  // set cursor to the bottom line
  cursorX = 0;
  cursorY = 24;
}//end fb_scrollUp

/** fb_print:
 * Print a string of text to the framebuffer
 * @param *str The character array to print
 */
int fb_print(char *str, unsigned int length) {
  // scroll the screen up if we are at the bottom
  if(cursorY == 10) {
    fb_scrollUp();
    fb_write_cell(0, 'X', FB_BLACK, FB_RED);
  }

  //fb_write_cell(0, 'X', FB_BLACK, FB_RED);

  unsigned int i = 0, j = 2 * (convertPosToFB(cursorX, cursorY)); // framebuffer location is twice the cursor position
  unsigned short x = 0, y = 0;

  // print the message to the framebuffer
  for(; i < length; i++) {

    // if there is a newline character then go to the next line
    if(str[i] == '\n') {
      y++;
      x = 0;
      cursorX = 0;
      j = 2 * (convertPosToFB(x, ++cursorY));
    } else {
      // print the character
      fb_write_cell(j, str[i], FB_BLACK, FB_GREEN);
      j+=2;

      // increment the cursor loction
      if(x < 80) {
        x++;
      } else {
        x = 0;
        cursorX = 0;
        y++;
      }//end cursor handleing
    }// end newline check
  }//end printing the message

  // update the cursor position
  fb_move_cursor((cursorX + x) - 1, cursorY + y); // subtract 1 from x so we don't get an extra space

  return 0;
}//end fb_print

/** fb_println:
 * Print a string of text to the framebuffer and move to the next line
 * @param *buf The character array to print
 */
int fb_println(char *str, unsigned int length) {
  fb_print(str, length);

  // move to the next line
  fb_move_cursor(0, ++cursorY);

  return 0;
}

/** s_print:
 * Print a string of text to the serial port
 * @param *buf The character array to print
 */
 /*
int s_print(char *buf) {

  return 0;
}
*/
/** s_println:
 * Print a string of text to the serial port and move to the next line
 * @param *buf The character array to print
 */
 /*
int s_println(char *buf) {
  s_print(buf);

  return 0;
}
*/
