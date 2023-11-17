#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {"Choice 1", 
                    "Choice 2",
                    "Choice 3",
                    "Choice 4",
                    "Choice 5",
                    "Exit"};

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu, int highlight);


int main() {
    WINDOW *menu;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and wown, Press enter to select a choice");
    refresh();
    print_menu(menu, highlight);

    while(1) {
        c = wgetch(menu);
        switch(c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else 
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else 
                    ++highlight;
                break;
            case 10:
                choice = highlight; 
                break;
                break;
        }
    }


    return 0;
}
