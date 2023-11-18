#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>

int len(char *buf) {
    int count = 0;
    for(int i = 0; ;i++) {
        if (buf[i] == '\0') {
            count = i;
            break;
        }
    }
    return count;
}



void str_copy(char *target, char *buf) {
    for(int i = 0; ;i++) {
        target[i] = buf[i];
        if (buf[i] == '\0') {
            break;
        }
    }
}

char **get_content_from_dir(char *path, int *size) {
    char **content = malloc(sizeof(char *) * (*size));
    DIR *dir = opendir(path);

    struct dirent *d;
    int i = 0;
    while((d = readdir(dir)) != NULL) {
        if (i >= *size) {
            *size <<= 1;
            content = realloc(content, sizeof(char *) * (*size));
        } 
        content[i] = malloc(sizeof(char) * len(d->d_name));
        str_copy(content[i], d->d_name);
        i++;
    }
    *size = i;
    return content;
}

void print_in_window_dir() {
    int size = 20;
    char **content = get_content_from_dir("/home/maximhrunenko/", &size);

    for(int i = 0; i < size; i++) {
        mvprintw(i + 1, 2, "%s", content[i]);
    }
}


int main() {
    int y, x;
    int ch;

    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, y, x);
    box(stdscr, 0, 0);

    print_in_window_dir();
    char curs = '>';
    int curs_y = 1;
    int curs_x = 1;
    mvaddch(curs_y, curs_x, curs);
    refresh();

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {
            case KEY_DOWN:
                if (curs_y == y) break;
                mvaddch(curs_y++, curs_x, ' ');
                mvaddch(curs_y, curs_x, curs);
                break;
            case KEY_UP:
                if (curs_y == 1) break;
                mvaddch(curs_y--, curs_x, ' ');
                mvaddch(curs_y, curs_x, curs);
                break;
        }
        refresh();
    }
    endwin();
    return 0;
}
