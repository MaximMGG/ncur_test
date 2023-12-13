


#ifndef _DIR_LIST_
#define _DIR_LIST_

#define T_EXECUTABLE 1
#define T_DIR 2
#define T_READABLE 3
#define B_MAX_SIZE 20


struct dir_list {
    char type;
    char *file_name;
};

typedef struct d_file_list {
    struct dir_list **files;
    unsigned int len; 
    unsigned int max_size;
}D_LIST;


typedef struct copy_file {
    char **file_path_buf;
    unsigned int buf_len;
    char *file_path;
} copy_buff;


D_LIST *create_dirlist();
void add_file(D_LIST, char l_type, char *l_file_name);


void destroy_dirlist();



#endif // _DIR_LIST_
