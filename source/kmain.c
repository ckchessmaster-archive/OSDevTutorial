#include "io.h"

/* The main program loop */
int main() {
  char hello[] = "Hello World!";
  fb_println(hello, sizeof(hello));
  char tooMuch[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30";
  fb_println(tooMuch, sizeof(tooMuch));
  
  return 0;
}
