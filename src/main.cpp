#include "FileHandler.h"
#include "helper.h"
#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf(COLOR_RED "fatal error:" COLOR_RESET
                     " no input file or command given\n");
  }

  if (argc >= 2) {
    if (!strcmp("--help", argv[1])) {
      help();
    }

    if (argv[2] != nullptr) {
      FileHandler myfile(argv[2]);
      if (!strcmp("-c", argv[1])) {
        printf("%d %s", myfile.fileSize(), argv[2]);
      } else if (!strcmp("-l", argv[1])) {
        printf("%d %s", myfile.lineCount(), argv[2]);
      } else if (!strcmp("-w", argv[1])) {
        printf("%d %s", myfile.wordCount(), argv[2]);
      } else {
        printf("%d %s", myfile.charCount(), argv[2]);
      }
    }
  }
}