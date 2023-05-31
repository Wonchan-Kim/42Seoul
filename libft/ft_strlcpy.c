#include "libft.h"
size_t ft_strlcpy(char *dest, const char *src, size_t size){
    /*
        safer alternative of strncpy. Used to copy a string from the source to destination buffer while ensuring proper null
        termination and avoiding buffer overflow. 
        dest: A pointer to the destination buffer where the copied string will be stored.
        src: A pointer to the source string to be copied.
        size: The size of the destination buffer, which represents the maximum number of characters that can be copied (including the null terminator).


        How does it assure the copied string ends with proper null charcter and avoids buffer overflow?
        The strlcpy function will copy characters from the source string to the destination buffer until either size-1 
        characters have been copied, or the end of the source string is reached (whichever comes first).          ------->       (1)
        It guarantees that the destination buffer is always null-terminated, regardless of whether truncation occurred. 

        Return value is the length of the source in size_t type. 
    */

    size_t i = 0;
    size_t return_val = 0;
    
    while(i < size - 1 && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }


    dest[i] = '\0';

    while(src[return_val] != '\0')
        return_val++;
    return return_val;
}