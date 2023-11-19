#include "../headers/util.h"


char *concatString(char *target, char *buffer, char symbol) {
    char *tmp = malloc(sizeof(char) * (strlen(target) + strlen(buffer)));
    int i = 0, j = 0;

    for(;;i++) {
        if (target[i] == '\0') {
            break;
        }
        tmp[i] = target[i];
    }
    if (symbol != 0) {
        tmp[i++] = symbol;
    }

    for(;;i++, j++) {
        tmp[i] = buffer[j];
        if (buffer[j] == '\0') {
            break;
        }
    }

    return tmp;
}


char *catStringFromEnd(char *buf, char symbol) {
    int count = 0;
    for(int i = 0; ; i++) {
        if (buf[i] == symbol) count++;
        if (buf[i] == '\0') break;
    }

    for(int i = 0; ; i++) {
        if(buf[i] == symbol) count--;
        if (count == 0) {
            buf[i] = '\0';
            break;
        }

    }

    return buf;
}



