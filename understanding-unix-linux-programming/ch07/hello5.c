#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#define ROW 10
#define LEFTEDGE 10
#define RIGHTEDGE 50

int dir = +1;
int pos = 1;
char message[] = "hello jocs";
char blank[] = "             ";

int main(void) {
  initscr();
  clear();
  while (1) {
    move(ROW, pos);
    addstr(message);
    move(LINES - 1, COLS - 1);
    refresh();
    sleep(1);
    move(ROW, pos);
    addstr(blank);
    refresh();
    pos += dir;
    if (pos > RIGHTEDGE) {
      dir = -1;
    }
    if (pos < LEFTEDGE) {
      dir = +1;
    }
  }
  clear();
  endwin();
}