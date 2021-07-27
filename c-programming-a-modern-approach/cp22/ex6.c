#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  unsigned char buffer[10], offset, n, i;
  if (argc != 2) {
    printf("Enter filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    printf("Can not open file\n");
    exit(EXIT_FAILURE);
  }

  printf("Offset              Bytes            Characters\n");
  printf("------  ---------------------------  ----------\n");

  for (offset = 0; ;offset += 10) {
    n = fread(buffer, 1, 10, fp);
    if (n == 0) {
      break;
    }
    printf("%-6d", offset);
    for (i = 0; i < n; i++) {
      printf("%2X ", buffer[i]);
    }
    for (;i < 10; i++) {
      printf("   ");
    }
    printf(" ");
    for (i = 0; i < n; i++) {
      if (!isprint(buffer[i])) {
        buffer[i] = '.';
      }
      printf("%c", buffer[i]);
    }
    printf("\n");
  }
  fclose(fp);
  return 0;
}