#include <ncurses.h>

WINDOW *create_window(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main() {


    WINDOW *win;
    int startx, starty, width, height;
    int ch;

    initscr();
    cbreak();

    keypad(stdscr, TRUE);

    height = 30;
    width = 50;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    box(stdscr, 0, 0);
    refresh();
    win = create_window(height, width, starty, startx);

    while((ch = getch()) != KEY_F(1)) {
    mvprintw(0, 0, "Press F1 to exit");
        switch(ch) {
            case KEY_LEFT:
                destroy_win(win);
                win = create_window(height, width, starty, --startx);
                mvwprintw(win, 1, 1, "left");
                wrefresh(win);
                break;
            case KEY_RIGHT:
                destroy_win(win);
                win = create_window(height, width, starty, ++startx);
                mvwprintw(win, 1, 1, "right");
                wrefresh(win);
                break;
            case KEY_UP:
                destroy_win(win);
                win = create_window(height, width, --starty, startx);
                mvwprintw(win, 1, 1, "up");
                wrefresh(win);
                break;
            case KEY_DOWN:
                destroy_win(win);
                win = create_window(height, width, ++starty, startx);
                mvwprintw(win, 1, 1, "down");
                wrefresh(win);
                break;
        }
    }
    refresh();
    endwin();
    return 0;
}


WINDOW *create_window(int height, int width, int starty, int startx) {
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);

    wrefresh(local_win);

    return local_win;
}

void destroy_win(WINDOW *local_win) {
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}

