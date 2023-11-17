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

int main() {
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    
    DIR *dir = opendir("/home/maximhrunenko/");

    struct dirent *d;
    char ** dir_info= malloc(sizeof(char *) * 20);
    int i = 0;

    while((d = readdir(dir)) != NULL) {
        dir_info[i] = malloc(sizeof(char) * len(d->d_name));
        str_copy(dir_info[i], d->d_name);
        i++;
    }

    for(int j = 0; j < i; j++) {
        mvprintw(j, 0, "%s", dir_info[j]);
    }


    printw("Type any character to see it in bold\n");
    ch = getch();
    
    if (ch == KEY_F(1)) {
        printw("F1 key pressed");
    } else {
        printw("The pressed key is : ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(ch);
    }
    addch(ch | A_BOLD | A_UNDERLINE);
    closedir(dir);
    free(dir_info);
    free(d);

    refresh();
    getch();
    endwin();

    return 0;
}
