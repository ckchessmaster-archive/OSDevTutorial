#include "io.h"

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

/* The framebuffer for writing to the screen */
char *fb = (char *) 0x000B8000;
unsigned short cursorPos = 0;
/** fb_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos) {
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
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned bg) {
  fb[i] = c;
  fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

int fb_writeln(char *buf, unsigned int len) {
  unsigned int x = 0, i = 0;

  // print the message to the framebuffer
  for(; i < (2 * len); i+=2) {
    //If the character is a newline go down a line
    if(buf[x] == '\n') {
      //fb_move_cursor();
    } else {
      fb_write_cell(i, buf[x], FB_BLACK, FB_GREEN);
      cursorPos++;
    }
    x++;
  }
  return 0;
}

/* The main program loop */
int main() {
  char message[24] = "Hello World!\n more text";
  fb_writeln(message, 24);
  fb_writeln(message, 24);

  return 0;
}