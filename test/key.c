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
            default:
                mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        print_menu(menu, highlight);
        if (choice != 0)
            break;
    }
    mvprintw(23, 0, "You choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol();
    refresh();
    endwin();
    return 0;
}



void print_menu(WINDOW *menu, int highlight) {
    int x, y, i;
    x = 2;
    y = 2;
    box(menu, 0, 0);
    for(i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu, A_REVERSE);
            mvwprintw(menu, y, x, "%s", choices[i]);
            wattroff(menu, A_REVERSE);
        } else {
            mvwprintw(menu, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu);
}
