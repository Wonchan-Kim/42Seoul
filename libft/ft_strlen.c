#include "libft.h"

/*size_t is an unsigned integer type defined in the 'stddef.h' header file. It is used to represent the size of the objects in bytes( > 0).*/

size_t ft_strlen(const char *str){
    size_t i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}