#include <ncurses.h>
#include <ar_list.h>


#define CURS '>'
#define SPACE ' '

#define UP 1
#define DOWN 2

typedef struct w_win {
    WINDOW *win;
    int maxy, maxx;
    a_list *dir;
    int show_from, show_to;
    int cursory;
    int cursorx;
    char *cur_dir;
}W_WIN;


void moveCursUp(W_WIN *win);
void moveCursDown(W_WIN *win);
void showCreen(W_WIN *win);


W_WIN *initMainScreen(a_list *dir);

void printDir(W_WIN *win);
