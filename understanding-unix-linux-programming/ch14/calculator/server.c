#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <pthread.h>
#include "common.h"

pthread_t t;
pthread_attr_t attr;

void setup(void);
void* handle_request(void*);
void handle_get(char* path, int fd);
void handle_post(char* path, char* data, int fd);
FILE* write_response(int fd, int code, char* status, char* content_type);
char* get_content_type(char* filename);

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./server portnum\n");
    exit(1);
  }

  int fd;

  int sock_id = make_server_socket(atoi(argv[1]));
  if (sock_id == -1) {
    perror("Create server error, ");
    exit(1);
  }
  printf("Server listen on port: %d\n", atoi(argv[1]));
  setup();

  while (1) {
    fd = accept(sock_id, NULL, NULL);
    int* temp = (int*)malloc(sizeof(int));
    *temp = fd;
    pthread_create(&t, &attr, handle_request, temp);
  }

  exit(0);
}

void setup(void) {
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
}

void* handle_request(void* fd) {
  int ifd = *(int*)fd;
  int content_len = 0;
  char request[BUFSIZ], method[BUFSIZ], path[BUFSIZ];
  free(fd);
  FILE* fp = fdopen(ifd, "r");
  fgets(request, BUFSIZ, fp);
  printf("%s", request);
  sscanf(request, "%s %s", method, path);
  // Skip headers.
  while (fgets(request, BUFSIZ, fp) != NULL && strcmp(request, "\r\n") != 0) {
    if (strncmp(request, "Content-Length", 14) == 0) {
      content_len = atoi(request + 16);
      printf("Content-Length: %d\n", content_len);
    }
  }

  if (strcmp(method, "GET") == 0) {
    handle_get(path, ifd);
  } else if (strcmp(method, "POST") == 0) {
    fgets(request, content_len + 1, fp);
    request[content_len] = '\0';
    printf("%s", request);
    handle_post(path, request, ifd);
  } else {
    // TODO
  }

  return NULL;
}

FILE* write_response(int fd, int code, char* status, char* content_type) {
  FILE* fp = fdopen(fd, "w");

  if (fp != NULL) {
    fprintf(fp, "HTTP/1.1 %d %s\r\n", code, status);
    fprintf(fp, "content-type: %s\r\n\r\n", content_type);
  }

  return fp;
}

char* get_content_type(char* filename) {
  char* type = "text/html";
  char* pot;

  if ((pot = strchr(filename, '.')) != NULL) {
    char* ext = pot + 1;
    if (strcmp(ext, "js") == 0) {
      type = "text/javascript";
    } else if (strcmp(ext, "css") == 0) {
      type = "text/css";
    }
  }

  return type;
}

void handle_get(char* path, int fd) {
  printf("GET: %s\n", path);
  if (strcmp(path, "/") == 0) {
    strcat(path, "index.html");
  }
  char* filename = path + 1;
  char pathname[BUFSIZ];
  int c;
  strcpy(pathname, "./client/");
  strcat(pathname, filename);
  char* content_type = get_content_type(filename);

  printf("pathname: %s\n", pathname);
  printf("content_type: %s\n", content_type);

  FILE* fp_sock = write_response(fd, 200, "OK", content_type);
  FILE* fp_file = fopen(pathname, "r");

  if (fp_file != NULL) {
    while ((c = getc(fp_file)) != EOF) {
      putc(c, fp_sock);
    }
  }

  fclose(fp_sock);
  fclose(fp_file);
}

void handle_post(char* path, char* data, int fd) {
  char expr[BUFSIZ];
  char cmd[BUFSIZ];
  int c;
  char* i = strstr(data, ":\"");
  char* j = strstr(data, "\"}");
  strncpy(expr, i + 2, j - i - 2);

  printf("exp: %s\n", expr);

  strcpy(cmd, "echo \"");
  strcat(cmd, expr);
  strcat(cmd, "\" | bc");
  printf("POST: %s, cmd: %s\n", path, cmd);

  FILE* cmd_fp = popen(cmd, "r");
  FILE* sock_fp = write_response(fd, 200, "OK", "application/json");
  fprintf(sock_fp, "{\"value\":\"");
  while ((c = getc(cmd_fp)) != EOF) {
    if (c != '\n')
      putc(c, sock_fp);
  }
  fprintf(sock_fp, "\"}");
  pclose(cmd_fp);
  fclose(sock_fp);
}