#include "helper.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf(COLOR_RED "fatal error:" COLOR_RESET
                     " no input file or command given\n");
  }

  if (argc > 2) {
    if (strcmp(argv[1], "-l") || strcmp(argv[1], "--l")) {
      printf("argument 2: %s\n", argv[1]);
    }
    printf("argument 3: %s\n", argv[2]);
  }
}