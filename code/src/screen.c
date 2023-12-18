#include "../headers/screen.h"
#include <ncurses.h>

#define AT_CP(a) attron(COLOR_PAIR(a))
#define AT_CPOF(a) attroff(COLOR_PAIR(a))

void resetscreen(M_WIN *win) {

}

void initdirpair() {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
}

void showscreen(M_WIN *win) {
    int tmp = 0;
    for(int i = 0; i < win->list->len; i++) {
       tmp = win->list->files[i]->type; 
       if (tmp == T_EXECUTABLE) {
           AT_CP(T_EXECUTABLE);
           mvaddstr(i + 1, 2, win->list->files[i]->file_name);
           AT_CPOF(T_EXECUTABLE);
       } else if (tmp == T_DIR) {
           attron(COLOR_PAIR(2) | A_BOLD);
           mvaddstr(i + 1, 2, win->list->files[i]->file_name);
           attroff(COLOR_PAIR(2) | A_BOLD);
       } else {
           AT_CP(T_READABLE);
           mvaddstr(i + 1, 2, win->list->files[i]->file_name);
           AT_CPOF(T_READABLE);
       }
    }
    refresh();
}

void curs_move(M_WIN *win, char direction) {
    if (direction == DOWN) {
        if (win->cury >= win->maxy - 1) return;
        if (win->cury == win->list->len) return;
        if ((win->list->len - win->from) > win->maxy) {
            if (win->cury < win->maxy - 8) {
                mvaddch(win->cury, win->curx, ' ');
                mvaddch(win->cury++, win->curx, '>');
                return;
            } else {
                win->from++;
                return;
            }
        } else {
                mvaddch(win->cury, win->curx, ' ');
                mvaddch(win->cury++, win->curx, '>');
                return;
        }
    } else {
        if (win->cury == 1) return;
        if (win->from == 0) {
                mvaddch(win->cury, win->curx, ' ');
                mvaddch(win->cury--, win->curx, '>');
                return;
        } else {
            if (win->cury > 8) {
                mvaddch(win->cury, win->curx, ' ');
                mvaddch(win->cury--, win->curx, '>');
                return;
            } else {
                win->from--;
                return;
            }
        }
    }
}
