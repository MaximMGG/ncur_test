#include <ncurses.h>
#include <stdlib.h>


int main(int argc, char **argv) {

    int ch, prev, row, col;
    prev = EOF;
    FILE *f;
    int y, x;

    if (argc != 2) {
        printf("Usage: %s <a c file name>\n", argv[0]);
        exit(1);
    }
    f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("Cannot open input file");
        exit(1);
    }
    initscr();

    getmaxyx(stdscr, row, col);
    while((ch = fgetc(f)) != EOF) {
        getyx(stdscr, y, x);
        if (y == (row - 1)) {
            attron(A_PROTECT);
            printw("<-Press Any Key->");
            attroff(A_PROTECT);
            getch();
            clear();
            move(0, 0);
        }
        if (prev == '/' && ch == '*') {
            attron(A_BOLD);
            getyx(stdscr, y, x);
            move(y, x - 1);
            printw("%c%c", '/', ch);
        } else {
            printw("%c", ch);
        }
        refresh();
        if (prev == '*' && ch == '/')
            attroff(A_BOLD);

        prev = ch;
    }

    endwin();
    fclose(f);
    return 0;
}
