#include "../headers/dirfunc.h"
#include <unistd.h>





void print_change_bufmode(WINDOW *win, boolean on) {
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    wattron(win, COLOR_PAIR(1) | A_BOLD);

    if (on) {
        mvwaddstr(win, 5, 80, "Bufferised copy off"); 
        sleep(1);
        // mvwaddstr(win, 5, 80, "                     "); 
    } else {
        mvwaddstr(win, 5, 80, "Bufferised copy on"); 
        sleep(1);
        // mvwaddstr(win, 5, 80, "                     "); 
    }
    wattroff(win, COLOR_PAIR(1) | A_BOLD);
}
