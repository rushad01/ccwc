#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include <cstdio>

void help() {
  printf("\nUsage: ccwc.exe [options] file...\n");
  printf("--help \t Display this information,\n");
  printf("-c     \t Output file size in bytes.\n");
  printf("-l     \t Output line count.\n");
  printf("-w     \t Output number words in a file.\n");
  printf("-m     \t Output number of characters in a file.\n");
}