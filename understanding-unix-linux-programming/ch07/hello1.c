#include <stdio.h>
#include <curses.h>

int main(void) {
  initscr();
  clear();
  move(10, 20);
  addstr("Hello Jocs");
  move(LINES - 1, 0);
  addstr("another string");
  refresh();
  getch();
  endwin();
  return 0;
}