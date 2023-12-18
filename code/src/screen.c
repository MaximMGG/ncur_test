#include "../headers/screen.h"
#include <ncurses.h>

#define AT_CP(a) attron(COLOR_PAIR(a))
#define AT_CPOF(a) attroff(COLOR_PAIR(a))

void resetscreen(M_WIN *win) {

}

void initdirpair() {
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
}

void showscreen(M_WIN *win) {
    int tmp = 0;
    for(int i = 0; i < win->list->len; i++) {
       tmp = win->list->files[i]->type; 
       if (tmp == T_EXECUTABLE) {
           AT_CP(T_EXECUTABLE);
           mvaddstr(i + 1, 1, win->list->files[i]->file_name);
           AT_CPOF(T_EXECUTABLE);
       } else if (tmp == T_DIR) {
           AT_CP(T_DIR);
           mvaddstr(i + 1, 1, win->list->files[i]->file_name);
           AT_CPOF(T_DIR);
       } else {
           mvaddstr(i + 1, 1, win->list->files[i]->file_name);
       }
    }
    refresh();
}

