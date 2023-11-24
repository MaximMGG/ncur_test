#ifndef _DIR_FUNC_
#define _DIR_FUNC_

typedef int boolean;
#define true 1
#define false 0


typedef struct s_copy_buf {
    char *last_copy;
    char **buffer;
    unsigned int buffer_len;
    boolean boofer_on;
} copyBuf;




#endif // _DIR_FUNC_
