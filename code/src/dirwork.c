#include "../headers/dirwork.h"




a_list *getContentFromDir(a_list *buf, char *path) {
        a_list *content;
    if (buf == NULL) {
        content = al_create(STRING, false, 0);
    } else {
        content = al_reset(buf);
    }

    DIR *dir = opendir(path);
    struct dirent *ddir;

    if (dir == NULL) {
        return NULL;
    }

    while((ddir = readdir(dir)) != NULL) {
        al_add(content, ddir->d_name, STRING);
    }

    closedir(dir);
    free(ddir);

    return content;
}
