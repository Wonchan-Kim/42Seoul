#include "libft.h"

char *strchr(const char *str, int c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == (char)c) {
            return (char *)(str + i);
        }
        i++;
    }
    return NULL;
}