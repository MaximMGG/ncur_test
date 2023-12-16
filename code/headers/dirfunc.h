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
} M_WIN;



#endif //_DIR_FUNC_
