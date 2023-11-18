#include <ncurses.h>

int main() {

    initscr();
    printw("Верхний левый угол "); addch(ACS_ULCORNER); printw("\n");
    printw("Левый нижний угол "); addch(ACS_LLCORNER); printw("\n");
    printw("Правый нижний угол "); addch(ACS_LRCORNER); printw("\n");
    printw("Тройник направлен вправо "); addch(ACS_LTEE); printw("\n");
    printw("Тройник направлен влево "); addch(ACS_RTEE); printw("\n");
    printw("Тройник направлен вверх "); addch(ACS_BTEE); printw("\n");
    printw("Тройник направлен вниз "); addch(ACS_TTEE); printw("\n");
    printw("Горизонтальная линия "); addch(ACS_HLINE); printw("\n");
    printw("Вертикальная линия "); addch(ACS_VLINE); printw("\n");
    printw("Большой плюс или пересечение "); addch(ACS_PLUS); printw("\n");
    printw("Сканировать строку 1 "); addch(ACS_S1); printw("\n");
    printw("Сканировать строку 3 "); addch(ACS_S3); printw("\n");
    printw("Сканировать строку 7 "); addch(ACS_S7); printw("\n");
    printw("Сканировать строку 9 "); addch(ACS_S9); printw("\n");
    printw("Алмаз "); addch(ACS_DIAMOND); printw("\n");
    printw("Шахматная доска (пунктир) "); addch(ACS_CKBOARD); printw("\n");
    printw("Символ градуса "); addch(ACS_DEGREE); printw("\n");
    printw("Символ плюс/минус "); addch(ACS_PLMINUS); printw("\n");
    printw("Пуля "); addch(ACS_BULLET); printw("\n");
    printw("Стрелка, указывающая влево "); addch(ACS_LARROW); printw("\n");
    printw("Стрелка, указывающая вправо "); addch(ACS_RARROW); printw("\n");
    printw("Стрелка вниз "); addch(ACS_DARROW); printw("\n");
    printw("Стрелка вверх "); addch(ACS_UARROW); printw("\n");
    printw("Доска квадратов "); addch(ACS_BOARD); printw("\n");
    printw("Символ фонаря "); addch(ACS_LANTERN); printw("\n");
    printw("Сплошной квадратный блок "); addch(ACS_BLOCK); printw("\n");
    printw("Знак меньше/равно "); addch(ACS_LEQUAL); printw("\n");
    printw("Знак большего/равно "); addch(ACS_GEQUAL); printw("\n");
    printw("Пи "); addch(ACS_PI); printw("\n");
    printw("Не равно "); addch(ACS_NEQUAL); printw("\n");
    printw("Знак британского фунта стерлингов "); addch(ACS_STERLING); printw("\n");
    refresh();
    getch();
    endwin();

    return 0;
}
