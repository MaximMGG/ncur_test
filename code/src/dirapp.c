#include <ncurses.h>
#include <stdio.h>
#include <ar_list.h>
#include <unistd.h>
#include "../headers/screen.h"
#include "../headers/dirwork.h"



int main() {

    char *user_login = getlogin();
    char *pwd = getcwd(pwd, 200);
    int ch;

    int x = 0, y = 0, maxx, maxy;
    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, y, x);
    W_WIN *main_win = malloc(sizeof(*main_win));
    main_win->win = stdscr;
    main_win->maxy = maxy;
    main_win->maxx = maxx;
    main_win->dir = getContentFromDir(pwd);

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_ENTER:
                break;
            //(TODO) (maxim) here need to implement functional, ditails in -notes 
            case 'c':
                break;
            //(TODO) (Maxim) here will be some command line
            case ':':
                break;
        }
    }

    endwin();
    return 0;
}
