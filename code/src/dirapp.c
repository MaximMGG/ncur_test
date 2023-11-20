#include <ncurses.h>
#include <stdio.h>
#include "../headers/ar_list.h"
#include <unistd.h>
#include "../headers/screen.h"
#include "../headers/dirwork.h"
#include "../headers/util.h"



void openDir(W_WIN *win);
void closeDir(W_WIN *win);


int main() {
    getchar();

    char *user_login = getlogin();
    char *pwd = getcwd(pwd, 200);
    int ch;

    initscr();
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    W_WIN *main = initMainScreen(getContentFromDir(NULL, pwd));
    main->cur_dir = malloc(sizeof(char) * strlen(pwd));
    strcpy(main->cur_dir, pwd);
    printDir(main);
    showCreen(main);
    mvwaddch(main->win, 1, 1, CURS);

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {
            case 'k':
            case KEY_UP:
                moveCursUp(main);
                showCreen(main);
                break;
            case 'j':
            case KEY_DOWN:
                moveCursDown(main);
                showCreen(main);
                break;
            case 'e':
                //TODO (maxim) rewrite this for working not only for dirrectories
                openDir(main);
                showCreen(main);
                break;
            case 'b':
                closeDir(main);
                showCreen(main);
                break;
            //(TODO) (maxim) here need to implement functional, ditails in -notes 
            case 'c':
                break;
            //(TODO) (Maxim) here will be some command line
            case ':':
                break;
        }
    }

    endwin();
    return 0;
}


void openDir(W_WIN *win) {
    char *new_dir;
    if (win->dir->len > win->maxy) {
        if (win->show_from == 0) {
            new_dir = al_get(win->dir, NULL, win->cursory - 1); 
        } else {
            new_dir = al_get(win->dir, NULL, win->cursory - 1 - win->show_to);
        }
    } else {
        new_dir = al_get(win->dir, NULL, win->cursory - 1); 
    }

    win->cur_dir = concatString(win->cur_dir, new_dir, '/');
    a_list *buf = getContentFromDir(win->dir, new_dir);
    if (buf == NULL) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1) | A_BLINK);
        mvwprintw(win->win, 3, 20, "This is not a dirrectory!!!");
        sleep(500);
        attroff(COLOR_PAIR(1) | A_BLINK);
    } 
    win->dir = buf;
    restartWin(win);
    win->cursory = 1;
    win->show_from = 0;
    if (win->dir->len > win->maxy) {
        win->show_to = win->maxy - 1;
    } else {
        win->show_to = win->dir->len - 1;
    }

    printDir(win);
}


void closeDir(W_WIN *win) {
    char *new_dir = catStringFromEnd(win->cur_dir, '/');
    if (strlen(new_dir) < 1) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1) | A_BLINK);
        mvwprintw(win->win, 3, 20, "Can not go back here is root dir");
        sleep(500);
        attroff(COLOR_PAIR(1) | A_BLINK);
    }
    strcpy(win->cur_dir, new_dir);
    a_list *buf = getContentFromDir(win->dir, new_dir);
    win->dir = buf;
    restartWin(win);
    win->cursory = 1;
    win->show_from = 0;
    if (win->dir->len > win->maxy) {
        win->show_to = win->maxy - 1;
    } else {
        win->show_to = win->dir->len - 1;
    }
    printDir(win);
}


