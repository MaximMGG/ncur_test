#include <ar_list.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/screen.h"
#include "../headers/dirwork.h"
#include "../headers/util.h"
#include "../headers/help.h"
#include "../headers/dirfunc.h"



void openDir(W_WIN *win);
void closeDir(W_WIN *win);


int main() {
    char *user_login = getlogin();
    char *pwd = getcwd(pwd, 200);
    int ch;

    initscr();

    raw();
    cbreak();
    noecho();
    curs_set(0);

    W_WIN *main = initMainScreen(getContentFromDir(NULL, pwd));
    keypad(main->win, TRUE);

    main->cur_dir = malloc(sizeof(char) * strlen(pwd));
    strcpy(main->cur_dir, pwd);
    printDir(main);
    showCreen(main);
    showInfoScreen();
    mvwaddch(main->win, 1, 1, CURS);
    wrefresh(main->win);

    while((ch = wgetch(main->win)) != KEY_F(1)) {
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
            case '\n':
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
                halfdelay(200);
                ch = wgetch(main->win);
                if (ch == 'b') {
                    if (main->copy_buf_on == true) {
                        main->copy_buf_on = false;    
                        print_change_bufmode(main->win, true);
                    } else {
                        main->copy_buf_on = true;    
                        print_change_bufmode(main->win, false);
                    }
                }
                break;
            //(TODO) (Maxim) here will be some command line
            case ':':
                break;
            case 'i': {
                showHelp();
                restartWin(main);
                printDir(main);
                showCreen(main);
                break;
                }
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

    if (!strcmp(new_dir, "..")) {
        closeDir(win);
        return;
    }

    new_dir = concatString(win->cur_dir, new_dir, '/');
    a_list *buf = getContentFromDir(win->dir, new_dir);
    if (buf == NULL) {
        return;
    } 

    win->dir = buf;
    free(win->cur_dir);
    win->cur_dir = new_dir;

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


