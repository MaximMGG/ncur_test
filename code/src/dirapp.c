#include <ncurses.h>
#include <stdio.h>
#include <ar_list.h>
#include <unistd.h>
#include "../headers/screen.h"


int main() {

    char *user_login = getlogin();
    char *pwd = getcwd(pwd, 200);
    int ch;

    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    while((ch = getch()) != KEY_F(1)) {

    }

    endwin();
    return 0;
}
