#include "libft.h"
void *ft_memset(void *ptr, int value, size_t num){
    /*
    ptr: a pointer to the block of memory to be set
    value: the value to be set (it is passed as an int but will be converted to an unsigned char)
    num: the number of bytes to be set starting from the memory location pointed to by ptr
    note that value is converted into unsigned char to alter the memory with 'byte'. 
*/
    int i = 0;
    unsigned char * ans = (unsigned char *)ptr; //the value will be converted into unsigned char, therefore the type of the pointer that will be returned should be determined.
    while(i < num){
        ans[i] = (unsigned char)value;
        i++;
    }
    return ptr;
}