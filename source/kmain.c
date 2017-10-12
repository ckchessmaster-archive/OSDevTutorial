#include "io.h"

/* The main program loop */
int main() {
  char message[] = "Hello World!Hello World!Hello World!Hello World!Hello World!H"; //Max length = 61 characters
  fb_println(message, sizeof(message));
  fb_println(message, sizeof(message));

  return 0;
}
