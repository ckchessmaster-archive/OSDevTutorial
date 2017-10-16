#include "io.h"

/* The main program loop */
int main() {
  //char message[] = "000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999"; // wrap around text example
  char message[] = "Hello World!"; // 12 bytes
  fb_println(message, sizeof(message));
  fb_println(message, sizeof(message));
  fb_println(message, sizeof(message));

  return 0;
}
