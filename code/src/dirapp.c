#include "../headers/dirfunc.h"
#include "../headers/screen.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>



int main() {
    int ch;

    initscr();
    start_color();
    initdirpair();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    M_WIN *win = initdir();
    curs_set(0);

    char *path = malloc(sizeof(char) * 200);
    getcwd(path, 200);
    setpath(win, path);
    box(win->win, 0, 0);
    move(1, 1);
    win->list = getdircontent(win);
    mvaddch(1, 1, '>');
    showscreen(win);

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {
            case 'j':
            case KEY_DOWN: {
                        curs_move(win, DOWN);    
                        refresh();
                        break;
                 }
            case 'k':
            case KEY_UP: {
                        curs_move(win, UP);    
                        refresh();
                        break;
                 }
        }
    }

    endwin();
    return 0;
}
