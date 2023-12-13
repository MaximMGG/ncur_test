#include "../headers/dirlist.h"
#include <malloc.h>

D_LIST *create_dirlist() {
    D_LIST *list = (D_LIST *)malloc(sizeof(struct d_file_list) * B_MAX_SIZE);
    return list;
}
 

void add_file(D_LIST, char l_type, char *l_file_name);


void destroy_dirlist();
