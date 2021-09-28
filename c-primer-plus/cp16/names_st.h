#ifndef NAMES_H_
#define NAMES_H_
#include <string.h>

#define SLEN 32

struct names_st
{
  char first[SLEN];
  char last[SLEN];
};

// 类型定义
typedef struct names_st names;

// 函数原型
void get_names(names *);
void show_names(const names *);
char *s_gets(char * st, int n);
#endif