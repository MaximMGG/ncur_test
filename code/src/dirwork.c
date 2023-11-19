#include "../headers/dirwork.h"




a_list *getContentFromDir(char *path) {
    a_list *content = al_create(STRING, false, 0);

    DIR *dir = opendir(path);
    struct dirent *ddir;

    while((ddir = readdir(dir)) != NULL) {
        al_add(content, ddir->d_name, STRING);
    }

    closedir(dir);
    free(ddir);

    return content;
}
