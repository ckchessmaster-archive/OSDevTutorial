#include "io.h"

/* The main program loop */
int main() {
  char reallyLongMessage[] = "000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999"; // wrap around text example
  char message[] = "Hello World!"; // 12 bytes
  char newMessage[] = "Hello!\nWorld!";
  fb_println(newMessage, sizeof(newMessage));
  fb_println(message, sizeof(message));
  fb_println(reallyLongMessage, sizeof(reallyLongMessage));

  char printMessage1[] = "This is the start";
  char printMessage2[] = " of a longer message.\nSome more text.";
  fb_print(printMessage1, sizeof(printMessage1));
  fb_print(printMessage2, sizeof(printMessage2));

  char finalMessage[] = "Goodbye!";
  fb_println(finalMessage, sizeof(finalMessage));

  return 0;
}
