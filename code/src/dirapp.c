#include "../headers/dirfunc.h"
#include <unistd.h>
#include <stdlib.h>



int main() {
    int ch;

    initscr();
    start_color();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    M_WIN *win = initdir();

    char *path = malloc(sizeof(char) * 200);
    getcwd(path, 200);
    setpath(win, path);
    box(win->win, 0, 0);


    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {

        }
    }


    endwin();
    return 0;
}
