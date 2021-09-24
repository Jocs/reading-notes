#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";

int main(void)
{
  int auto_store = 40;
  char auto_string[] = "Auto char Array";
  int *pi;
  char *pcl;
  pi = (int *)malloc(sizeof(int));
  *pi = 32;
  pcl = (char *)malloc(strlen("Dynamic String") + 1);
  strcpy(pcl, "Dynamic String");
  printf("static store%d, %p\n", static_store, &static_store);
  printf("auto store %d, %p\n", auto_store, &auto_store);
  printf("dy pi %d, %p\n", *pi, pi);
  printf("pcg %s, %p\n", pcg, pcg);
  printf("auto string %s, %p\n", auto_string, auto_string);
  printf("pcl %s, %p\n", pcl, pcl);
  printf("%s at %p\n", "Dynamic String", "Dynamic String");

  free(pi);
  free(pcl);

  exit(0);
}