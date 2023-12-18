#include "../headers/dirfunc.h"
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>



M_WIN *initdir() {
    M_WIN *win = malloc(sizeof(M_WIN));
    win->list = create_dirlist();
    win->win = stdscr;
    getmaxyx(stdscr, win->maxy, win->maxx);
    win->cury = 1;
    win->curx = 1;
    win->path = NULL;

    return win;
}

void setpath(M_WIN *win, char *path) {
    if (win->path == NULL) {
        win->path = malloc(sizeof(char) * strlen(path));
        strcpy(win->path, path);
    }
}

M_WIN *destroydir(M_WIN *win) {
    free(win->list);
    free(win->path);
    free(win);
    win = NULL;
    return win;
}

D_LIST *getdircontent(M_WIN *win) {
    DIR *dir = opendir(win->path);
    struct dirent *dirr;
    struct stat f_stat;
    int i = 0;

    while((dirr = readdir(dir)) != 0) {
        char *tmp = dirr->d_name;

        if(stat(tmp, &f_stat) == 0) {
            if (S_ISREG(f_stat.st_mode)) {
                if (f_stat.st_mode & S_IXUSR) 
                    add_file(win->list, T_EXECUTABLE, dirr->d_name); 
                else 
                    add_file(win->list, T_READABLE, dirr->d_name); 
            } else if (S_ISDIR(f_stat.st_mode)) {
                    add_file(win->list, T_DIR, dirr->d_name); 
            } else {
                    add_file(win->list, T_READABLE, dirr->d_name); 
            }
        }
    }
    closedir(dir);
    free(dirr);
    return win->list;
}
