#include "../headers/dirfunc.h"



int main() {
    int ch;

    initscr();
    start_color();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    while((ch = getch()) != KEY_F(1)) {
        switch(ch) {

        }
    }


    endwin();
    return 0;
}
