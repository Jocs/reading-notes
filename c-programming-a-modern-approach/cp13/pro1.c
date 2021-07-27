#include <stdio.h>
#include <string.h>

#define STR_NUM 50

void read_word(char *w);

int main(void)
{
  char smallest_word[STR_NUM], largest_word[STR_NUM];
  char temp[STR_NUM];
  int i = 0;
  for (;;) {
    printf("Enter word: ");
    read_word(temp);

    i++;
    if (i == 1) {
      strcpy(smallest_word, temp);
      strcpy(largest_word, temp);
      continue;
    }
    if (strcmp(smallest_word, temp) > 0) {
      strcpy(smallest_word, temp);
    }
    if (strcmp(largest_word, temp) < 0) {
      strcpy(largest_word, temp);
    }
    if (strlen(temp) == 4) break;
  }
  printf("The total word count is %d\n", i);
  printf("The smallest word is %s\n", smallest_word);
  printf("The lagetest word is %s\n", largest_word);
}

void read_word(char *w)
{
  char ch;
  while ((ch = getchar()) != ' ' && ch != '\n')
    *w++ = ch;
  *w = '\0';
}