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

/* The main program loop */
int main() {
  fb_write_cell(0, 'H', FB_BLACK, FB_GREEN);
  fb_write_cell(2, 'E', FB_BLACK, FB_GREEN);
  fb_write_cell(4, 'L', FB_BLACK, FB_GREEN);
  fb_write_cell(6, 'L', FB_BLACK, FB_GREEN);
  fb_write_cell(8, 'O', FB_BLACK, FB_GREEN);
  fb_write_cell(10, ' ', FB_BLACK, FB_GREEN);
  fb_write_cell(12, 'W', FB_BLACK, FB_GREEN);
  fb_write_cell(14, 'O', FB_BLACK, FB_GREEN);
  fb_write_cell(16, 'R', FB_BLACK, FB_GREEN);
  fb_write_cell(18, 'L', FB_BLACK, FB_GREEN);
  fb_write_cell(20, 'D', FB_BLACK, FB_GREEN);
  fb_write_cell(22, '!', FB_BLACK, FB_GREEN);

  return 0;
}
