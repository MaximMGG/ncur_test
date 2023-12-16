#include "../headers/dirlist.h"
#include <malloc.h>
#include <string.h>

D_LIST *create_dirlist() {
    D_LIST *list = (D_LIST *)malloc(sizeof(* list));
    list->files = (struct dir_list **)malloc(sizeof(struct dir_list *) * B_MAX_SIZE);

    for (int i = 0; i < B_MAX_SIZE; i++) {
        list->files[i] = (struct dir_list *)malloc(sizeof(struct dir_list));
        list->files[i]->type = 0;
    }

    list->len = 0;
    list->max_size = B_MAX_SIZE;
    return list;
}
 

void add_file(D_LIST *d_list, char l_type, char *l_file_name) {
    d_list->files[d_list->len]->type = l_type;
    d_list->files[d_list->len]->file_name = malloc(sizeof(char) * strlen(l_file_name) + 1);
    strcpy(d_list->files[d_list->len++]->file_name, l_file_name);

    if (d_list->len >= d_list->max_size) {
        d_list->max_size <<= 1;
        d_list->files = (struct dir_list **) realloc(d_list->files, sizeof(struct dir_list *) * d_list->max_size);

        for(int i = d_list->len; i < d_list->max_size; i++) {
            d_list->files[i] = (struct dir_list *) malloc(sizeof(struct dir_list));
        }
    }
}


void destroy_dirlist(D_LIST *d_list) {
    for(int i = d_list->max_size, j = d_list->len; i > 0 && j > 0; i++) {
        if (j == i) {
            free(d_list->files[j--]->file_name);
        }
        free(d_list->files[i]);
    }
    free(d_list);
}

