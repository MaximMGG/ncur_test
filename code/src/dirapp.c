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

    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    W_WIN *main = initMainScreen(getContentFromDir(pwd));

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {
            case KEY_UP:
                moveCursUp(main);
                showCreen(main);
                break;
            case KEY_DOWN:
                moveCursDown(main);
                showCreen(main);
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
