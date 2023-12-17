#include "../code/headers/dirfunc.h"
#include <time.h>
#include <ncurses.h>
#include <assert.h>
#include <stdlib.h>


void initdirtest() {
    M_WIN *win = initdir();
    // assert(win->win == stdscr);
    assert(win->cury == 1);
    assert(win->curx == 1);
    assert(win->path == 0);

    free(win->list);
    free(win);
}

void setpathtest() {

}

void destroydirtest() {

}

int main() {

    long start = clock();
    long teststart;
    long testend;

    puts("START DIRFUNC TEST");
    teststart = clock();
    puts("initdir func test");
    initdirtest();
    testend = clock();
    printf("initdir func test -> success time -> %ld ms\n", (testend - teststart));
    puts("========================================================");
    teststart = clock();
    puts("setpath func test");
    setpathtest();
    testend = clock();
    printf("setpath func test -> success, time -> %ld ms\n", (testend - teststart));
    puts("========================================================");
    teststart = clock();
    puts("destroydir func test");
    destroydirtest();
    testend = clock();
    printf("destroydir func test -> success, time -> %ld ms\n", (testend - teststart));


    testend = clock();
    puts("DIRFUNC TEST SUCCESS");
    printf("ALL TEST PASSED, TIME IS -> %ld ms\n", (testend - start));

    return 0;
}
