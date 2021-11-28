#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "common.h"

void read_til_crnl(FILE* fp);
void process_rq(char* rq, int fd);
void header(FILE* fp, char* content_type);
void cannot_do(int fd);
void do_404(char* item, int fd);
int isadir(char* f);
int not_exist(char* f);
void do_list(char* dir, int fd);
void do_cat(char* f, int fd);
char* file_type(char* f);

int main(int argc, char** argv) {
  int sock, fd;
  FILE* fpin;
  char request[BUFSIZ];
  sock = make_server_socket(atoi(argv[1]));
  if (sock == -1)
    exit(2);
  printf("server init:\n");
  while (1) {
    fd = accept(sock, NULL, NULL);
    fpin = fdopen(fd, "r");
    fgets(request, BUFSIZ, fpin);
    printf("got a call: request = %s", request);

    read_til_crnl(fpin);
    process_rq(request, fd);

    fclose(fpin);
  }
}

void read_til_crnl(FILE* fp) {
  char buf[BUFSIZ];
  while (fgets(buf, BUFSIZ, fp) != NULL && strcmp(buf, "\r\n") != 0);
}

void process_rq(char* rq, int fd) {
  char cmd[BUFSIZ], arg[BUFSIZ];
  if (fork() != 0)
    return;
  strcpy(arg, ".");
  if (sscanf(rq, "%s%s", cmd, arg + 1) != 2)
    return;
  printf("cmd: %s, arg: %s\n", cmd, arg);
  if (strcmp(cmd, "GET") != 0)
    cannot_do(fd);
  else if (not_exist(arg))
    do_404(arg, fd);
  else if (isadir(arg))
    do_list(arg, fd);
  // else if (ends_in_cgi(arg))
  //   do_exec(arg, fd);
  else
    do_cat(arg, fd);
}

void header(FILE* fp, char* content_type) {
  fprintf(fp, "HTTP/1.0 200 OK\r\n");
  if (content_type) {
    fprintf(fp, "Content-type: %s\r\n", content_type);
  }
}

void cannot_do(int fd) {
  FILE* fp = fdopen(fd, "w");
  fprintf(fp, "HTTP/1.0 501 Not Implementte\r\n");
  fprintf(fp, "Content-type: text/plain\r\n");
  fprintf(fp, "\r\n");
  fprintf(fp, "That command is not yet implemented\r\n");
  fclose(fp);
}

void do_404(char* item, int fd) {
  FILE* fp = fdopen(fd, "w");
  fprintf(fp, "HTTP/1.0 404 Not Found\r\n");
  fprintf(fp, "Content-type: text/plain\r\n");
  fprintf(fp, "\r\n");
  fprintf(fp, "That item you request: %s is not found\r\n", item);
  fclose(fp);
}

int isadir(char* f) {
  struct stat info;
  return (stat(f, &info) != -1 && S_ISDIR(info.st_mode));
}

int not_exist(char* f) {
  struct stat info;
  return stat(f, &info) == -1;
}

void do_list(char* dir, int fd) {
  FILE* fp;
  fp = fdopen(fd, "w");
  header(fp, "text/plain");
  fprintf(fp, "\r\n");
  fflush(fp);

  dup2(fd, 1);
  dup2(fd, 2);
  close(fd);
  execlp("ls", "ls", "-l", dir, NULL);
  perror(dir);
  exit(1);
}

char* file_type(char* f) {
  char* cp;

  if ((cp = strrchr(f, '.')) != NULL)
    return cp + 1;

  return "";
}

void do_cat(char* f, int fd) {
  char* extension = file_type(f);
  char* content = "text/plain";
  FILE* fpsock, * fpfile;
  int c;
  if (strcmp(extension, "html") == 0) {
    content = "text/html";
  }

  fpsock = fdopen(fd, "w");
  fpfile = fopen(f, "r");
  if (fpsock != NULL && fpfile != NULL) {
    header(fpsock, content);
    fprintf(fpsock, "\r\n");
    while ((c = getc(fpfile)) != EOF)
      putc(c, fpsock);
    putc(c, fpsock);
    fclose(fpsock);
    fclose(fpfile);
  }
}
