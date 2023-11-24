#include "../headers/help.h"

const char *help_instructions[] = {F1, ARROW_UP, ARROW_DOWN, ENTER, B};

void showHelp() {

    WINDOW *hot_key = newwin(HELP_LENGTH + 2, 60, 15, 60);
    box(hot_key, 0, 0);

    for(int i = 0; i < HELP_LENGTH; i++) {
        mvwaddstr(hot_key, i + 1 , 1, help_instructions[i]);
    }

    wrefresh(hot_key);
    wgetch(hot_key);
    delwin(hot_key);
}


