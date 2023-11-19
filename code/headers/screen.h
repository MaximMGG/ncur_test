#include <ncurses.h>
#include <ar_list.h>

typedef struct w_win {
    WINDOW *win;
    int maxy, maxx;
    a_list *dir;
    int show_from, show_to;
}W_WIN;


void moveCursUp(W_WIN *win);
void moveCursDown(W_WIN *win);
void showCreen(W_WIN *win);
