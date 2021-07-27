#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char ch, filename[20];
  if (argc != 2) {
    printf("You need to input filename\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "w+")) == NULL) {
    printf("Can not open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  printf("Open file %s\n", argv[1]);
  fclose(fp);
  printf("rename %s to another name:", argv[1]);
  scanf("%s", filename);
  printf("new name is %s", filename);
  rename(argv[1], filename);
  printf("Do you want to delete file %s\n", filename);
  scanf(" %c", &ch);
  if (ch == 'y') {
    remove(filename);
  }
  return 0;
}