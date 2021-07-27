#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part
{
  int number;
  char name[NAME_LEN + 1];
  int stock;
};

int main(int argc, char *argv[])
{
  FILE *in_fp1, *in_fp2, *out_fp;
  int num_read1, num_read2;
  struct part part1, part2;

  if (argc != 4) {
    printf("You need input 3 file name\n");
    exit(EXIT_FAILURE);
  }
  if ((in_fp1 = fopen(argv[1], "rb")) == NULL) {
    printf("Can not open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((in_fp2 = fopen(argv[2], "rb")) == NULL) {
    printf("Can not open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  if ((out_fp = fopen(argv[3], "wb")) == NULL) {
    printf("Can not open %s\n", argv[3]);
    exit(EXIT_FAILURE);
  }

  num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
  num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);

  while (num_read1 == 1 && num_read2 == 1) {
    if (part1.number > part2.number) {
      fwrite(&part2, sizeof(struct part), 1, out_fp);
      num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    } else if (part1.number < part2.number) {
      fwrite(&part1, sizeof(struct part), 1, out_fp);
      num_read1 = fread(&part1, sizeof(struct part), 1, in_fp2);
    } else {
      if (strcmp(part1.name, part2.name) != 0) {
        printf("name are not equal\n");
        exit(EXIT_FAILURE);
      }
      part1.stock += part2.stock;
      fwrite(&part1, sizeof(struct part), 1, out_fp);
      num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
      num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    }
  }

  while (num_read1 == 1) {
    fwrite(&part1, sizeof(struct part), 1, out_fp);
    num_read1 = fread(&part1, sizeof(struct part), 1, in_fp2);
  }
  while (num_read2 == 1) {
    fwrite(&part2, sizeof(struct part), 1, out_fp);
    num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
  }

  fclose(in_fp1);
  fclose(in_fp2);
  fclose(out_fp);
  return 0;
}