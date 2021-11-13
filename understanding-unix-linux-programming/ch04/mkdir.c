#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define BUF_SIZE 256
#define MKDIR_MODE 0777

int main(int argc, char** argv) {
  bool is_p_mode = false;
  int opt;

  /*
  * The getopt() function incrementally parses a command line argument list argv and
  * returns the next known option character.  An option character is known if it has been
  *  specified in the string of accepted option characters, optstring.
  */
  while ((opt = getopt(argc, argv, "p")) != -1) {
    switch (opt) {
    case 'p': is_p_mode = true; break;
    default:
      fprintf(stderr, "Usage: %s [-p] [file...]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (!is_p_mode) {
    mkdir(argv[1], MKDIR_MODE);
  } else {
    char* pt_start = argv[2];
    char* pt_end;
    char folder[BUF_SIZE];
    int count = 0;
    struct stat st;

    printf("%d\n", is_p_mode);

    while ((pt_end = strstr(pt_start, "/")) != NULL) {
      if (strlen(folder) != 0) {
        folder[count++] = '/';
      }
      while (pt_start != pt_end) {
        folder[count++] = *pt_start;
        pt_start++;
      }

      folder[count] = '\0';

      stat(folder, &st);
      if (!S_ISDIR(st.st_mode)) {
        mkdir(folder, MKDIR_MODE);
      }
      pt_start = pt_end + 1;
    }

    mkdir(argv[2], MKDIR_MODE);
  }
}