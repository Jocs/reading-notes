#include <stdio.h>
#include <unistd.h>
#include <curses.h>

int main(void) {
  initscr();
  clear();
  int i;
  for (i = 0; i < LINES; i++) {
    move(i, i + 1);
    if (i % 2 == 1) {
      standout();
    }
    addstr("hello jocs");
    if (i % 2 == 1) {
      standend();
    }
    refresh();
    sleep(1);
    move(i, i + 1);
    addstr("            ");
  }
  refresh();
  endwin();
}