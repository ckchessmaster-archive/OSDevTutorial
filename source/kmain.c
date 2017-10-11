#include "io.h"

/* The main program loop */
int main() {
  char message[] = "Hello World!";
  fb_println(message, sizeof(message));
  //fb_println(message, 12);

  return 0;
}
