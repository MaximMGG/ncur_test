
#ifndef _SCREEN_
#define _SCREEN_
#include <ncurses.h>
#include "dirfunc.h"
#include "dirlist.h"

#define DOWN 22
#define UP 33


void initdirpair();

void resetscreen(M_WIN *win);

void showscreen(M_WIN *win);

void curs_move(M_WIN *win, char direction);


#endif









