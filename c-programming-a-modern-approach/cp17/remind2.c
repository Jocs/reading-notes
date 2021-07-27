#include <stdio.h>
#include <stdlib.h> // use malloc\realloc\calloc
#include <string.h> // use strcpy \ strcmp \ strcat

#define MAX_VOLUM 60
#define MAX_MSG_LEN 60

int readline(char *msg, int n);

int main(void)
{
  char *reminder[MAX_VOLUM];
  int day, num_remind = 0, i, j;
  char day_str[3];
  char remind_msg[MAX_MSG_LEN + 1];

  for (;;) {
    printf("Enter day and reminder:");
    scanf("%2d", &day);
    sprintf(day_str, "%2d", day);
    readline(remind_msg, MAX_MSG_LEN);

    if (day == 0) {
      break;
    }

    for (i = 0; i < num_remind; i++) {
      if (strcmp(day_str, reminder[i]) < 0)
        break; 
    }

    for (j = num_remind; j > i; j--) {
      reminder[j] = reminder[j - 1];
    }

    reminder[i] = malloc(2 + strlen(remind_msg) + 1);

    strcpy(reminder[i], day_str);
    strcat(reminder[i], remind_msg);
    num_remind++;
  }

  printf("Day reminder:\n");

  for (i = 0; i < num_remind; i++) {
    printf("%s\n", reminder[i]);
  }
}

int readline(char *msg, int n)
{
  int i = 0;
  char ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      msg[i++] = ch;
  }
  msg[i] = '\0';
  return i;
}