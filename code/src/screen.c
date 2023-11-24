#include "../headers/screen.h"

void moveCursUp(W_WIN *win) {
    if (win->cursory == 1) {
        return;
    }

    if (win->show_from == 0) {
        mvwaddch(win->win, win->cursory, win->cursorx, SPACE);
        mvwaddch(win->win, --win->cursory, win->cursorx, CURS);
        return;
    }


    if (win->dir->len > win->maxy) {
        if (win->cursory < 8 && win->show_from > 0) {
            win->show_from--;
            win->show_to--;
            printDir(win);
            return;
        } else {
            mvwaddch(win->win, win->cursory, win->cursorx, SPACE);
            mvwaddch(win->win, --win->cursory, win->cursorx, CURS);
        } 
    }
     
}

void moveCursDown(W_WIN *win) {
    if (win->cursory >= win->maxy - 1) {
        return;
    }
    if (win->cursory > win->show_to) {
        return;
    }

    if (win->dir->len <= win->maxy) {
        mvwaddch(win->win, win->cursory, win->cursorx, SPACE);
        mvwaddch(win->win, ++win->cursory, win->cursorx, CURS);
        return;
    } else {
        if (win->cursory > win->maxy - 9) {
            if (win->show_to >= win->dir->len) {
                mvwaddch(win->win, win->cursory, win->cursorx, SPACE);
                mvwaddch(win->win, ++win->cursory, win->cursorx, CURS);
            }
            win->show_to++;
            win->show_from++;
            printDir(win);
            return;
        } else {
            mvwaddch(win->win, win->cursory, win->cursorx, SPACE);
            mvwaddch(win->win, ++win->cursory, win->cursorx, CURS);
        }
    }
} 

void showCreen(W_WIN *win) {
    wrefresh(win->win);
}

W_WIN *initMainScreen(a_list *dir) {
    W_WIN *main = malloc(sizeof(*main));
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);
    WINDOW *main_win = newwin(maxy - 3, maxx, 3, 0);


    main->win = main_win;
    getmaxyx(main->win, main->maxy, main->maxx);
    main->dir = dir; 
    main->cursory = 1;
    main->cursorx = 1;

    main->show_from = 0;

    if (main->dir->len >= main->maxy - 1) {
        main->show_to = main->maxy - 2;
    } else {
        main->show_to = main->dir->len - 1;
    }


    box(main->win, 0, 0);
    return main;
}

void printDir(W_WIN *win) {
    for(int i = win->show_from, j = 1; i <= win->show_to; i++, j++) {
        mvwprintw(win->win, j, 2, "%s", (char *)al_get(win->dir, NULL, i));
    }
}


void restartWin(W_WIN *win) {
    wclear(win->win);
    wrefresh(win->win);
    box(win->win, 0, 0);
    mvwaddch(win->win, 1, 1, CURS);
    win->cursorx = 1;
    win->cursory = 1;
}


void showInfoScreen() {
    int maxx = getmaxx(stdscr);
    WINDOW *info = newwin(3, maxx, 0, 0);
    mvwaddstr(info, 1, 1, "Type F1 for exit; Type \"i\" for getting key bindings help");
    box(info, 0, 0);
    wrefresh(info);
}


WINDOW *showKeysInfo() {
    WINDOW *hot_key = newwin(10, 60, 15, 60);
    box(hot_key, 0, 0);

    mvwaddstr(hot_key, 1, 1, "F1 - exit.");
    mvwaddstr(hot_key, 2, 1, "b - close dir.");
    mvwaddstr(hot_key, 3, 1, "Enter - open dir/file.");
    mvwaddstr(hot_key, 4, 1, "j/down_arrow - move down");
    mvwaddstr(hot_key, 5, 1, "k/up_arrow - move up");

    wrefresh(hot_key);

    return hot_key;
}

