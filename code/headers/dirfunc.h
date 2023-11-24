#ifndef _DIR_FUNC_
#define _DIR_FUNC_
#include <ar_list.h>
#include <ncurses.h>


typedef struct s_copy_buf {
    char *last_copy;
    char **buffer;
    unsigned int buffer_len;
} copyBuf;


//save single file
void save_copy_path(copyBuf *buf, char *path);

//save files in buffer
void save_copy_path_buf(copyBuf *buf, char **pathes, unsigned int size);

//paste single file
void paste_copy(copyBuf *buf);

//paste all files from buffer
void paste_all_bufferdfile(copyBuf *buf);

//paste one file from buffer
void paste_file_from_buffer(copyBuf *buf, int pos);

void print_change_bufmode(WINDOW *win, boolean on);


#endif // _DIR_FUNC_
