#include "../headers/dirfunc.h"
#include <stdlib.h>



M_WIN *initdir() {
    M_WIN *win = malloc(sizeof(M_WIN));
    win->list = create_dirlist();
    win->win = stdscr;
    getmaxyx(stdscr, win->maxy, win->maxx);
    win->cury = 1;
    win->curx = 1;
    win->path = NULL;

    return win;
}

void setpath(M_WIN *win, char *path) {

}

void destroydir(M_WIN *win) {
    free(win->list);
    free(win);
}
