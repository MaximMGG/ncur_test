#include <ncurses.h>
#include <stdlib.h>


int main() {

    initscr();
    printw("Hello world\n");
    getch();
    refresh();
    def_prog_mode();
    endwin();
    system("echo Bygaga");
    reset_prog_mode();

    refresh();

    printw("Another Hello\n");
    getch();
    refresh();
    endwin();
    return 0;
}
