#ifndef _DIR_FUNC_
#define _DIR_FUNC_
#include "dirlist.h"
#include <ncurses.h>

typedef struct {
    char *path;
    D_LIST *list;
    WINDOW *win;

    unsigned int cury;
    unsigned int curx;
    unsigned int maxy;
    unsigned int maxx;

    int from;
} M_WIN;

M_WIN *initdir();

void setpath(M_WIN *win, char *path);

M_WIN *destroydir(M_WIN *win);

D_LIST *getdircontent(M_WIN *win);

#endif //_DIR_FUNC_
