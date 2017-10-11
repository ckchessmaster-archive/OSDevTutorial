#include "ioasm.h"

/* The I/O ports */
#define FB_COMMAND_PORT   0x3D4
#define FB_DATA_PORT      0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

// The framebuffer for writing to the screen
char *fb = (char *) 0x000B8000;

/** fb_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param pos The new position of the cursor
 */
static void fb_move_cursor(unsigned short pos) {
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT, pos & 0x00FF);
}


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
}

/**
 * Get the length of the given string (char array)
 *
 * @param The string (char array) to get the length of
 */
static int getStrLength(char *buf) {
  unsigned int length = 0;

  

  return length;
}

/** fb_print:
 * Print a string of text to the framebuffer
 * @param *buf The character array to print
 */
int fb_print(char *buf) {
  unsigned
  return 0;
}

/** fb_println:
 * Print a string of text to the framebuffer and move to the next line
 * @param *buf The character array to print
 */
int fb_println(char *buf) {
  fb_print(buf);

  return 0;
}

/** s_print:
 * Print a string of text to the serial port
 * @param *buf The character array to print
 */
int s_print(char *buf) {

  return 0;
}

/** s_println:
 * Print a string of text to the serial port and move to the next line
 * @param *buf The character array to print
 */
int s_println(char *buf) {
  s_print(buf);

  return 0;
}
