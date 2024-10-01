#include "FileHandler.h"
#include "helper.h"
#include <cstdio>
#include <cstring>
#include <utility>

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
      FileHandler myFile(argv[2]);
      myFile.extractData();
      if (!strcmp("-c", argv[1])) {
        printf("%d %s", myFile.fileSize(), argv[2]);
      } else if (!strcmp("-l", argv[1])) {
        printf("%d %s", myFile.lineCount(), argv[2]);
      } else if (!strcmp("-w", argv[1])) {
        printf("%d %s", myFile.wordCount(), argv[2]);
      } else {
        printf("%d %s", myFile.charCount(), argv[2]);
      }
    }
  }
}