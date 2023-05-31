#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n){
    /*
    1. dest is a pointer to the destination memory location where the copied data will be stored.
    2. src is a pointer to the source memory location from where the data will be copied.
    3. n specifies the number of bytes to be copied.
    */
    /*
    Safe Overlapping Copy: If the source and destination memory regions overlap, memmove handles the copy correctly. 
    It detects the overlap and performs the copy in a way that ensures the integrity of the data.

    Byte-Level Copy: The memmove function copies the memory byte by byte. 
    It is not aware of the underlying data type and treats the memory as a sequence of bytes.

    Efficient Copy: The implementation of memmove aims to provide an efficient copy operation. 
                It takes advantage of various optimizations to improve performance.

    Portability: The memmove function is part of the C standard library and is available on most C compilers and platforms. 
                It provides a portable way to perform memory copying.
*/
 
    unsigned char* de = (unsigned char*) dest;
    unsigned char* s = (unsigned char*) src;
    size_t i = n;
    if( de > s && s + n > de){
        while( i > 0){
            de[i-1] = s[i-1];
            i--;
        }
    }
    else{
        while(i < n){
            de[i] = s[i];
            i++;
        }
    }
    return (void*)de;
}