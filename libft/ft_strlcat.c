#include "libft.h"
size_t ft_strlcat(char *dest, const char *src, size_t size){
    /*
    The strlcat function is a string concatenation function that is designed to be a safer alternative to the standard strcat function in C. 
    It provides a way to concatenate(결합) strings while ensuring proper null termination and avoiding buffer overflow.
    
    dest: A pointer to the destination buffer, which is the string where the concatenation result will be stored. 
            This buffer should be large enough to accommodate the concatenated string and its null terminator.

    src: A pointer to the source string, which is the string to be appended or concatenated to the destination.

    size: The size of the destination buffer. It represents the total size of the destination buffer, including the existing content and the null terminator.
            Before the user passes the value to the function, the user determines the size parameter in order to prevent the errors related to the memory. 

    The purpose of strlcat is to concatenate the source string (src) onto the end of the destination string (dest). 
    *It appends characters from the source to the destination until either size - strlen(dest) - 1 characters have been appended or the end of the source string is reached, whichever comes first. 
    The null terminator is always added to the destination buffer, ensuring proper null termination.

    
    */
   size_t p_of_d = 0;
   size_t p_of_src = 0;
   size_t d_len = strlen(dest);
   size_t src_len = strlen(src);
   
   while(src[p_of_src] && (p_of_src + d_len + 1 < size)){
     dest[p_of_d] = src[p_of_src];
     p_of_d++;
     p_of_src++;
   }
    dest[p_of_d] = '\0';

   /*
   Discussion over the return value

   The return value is different dpeneding on the result of the copy and the given value of size.
   (1)If the concatenation is successful and the entire source string is appended to the destination buffer without truncation
        Return value will be the sum of the original length of the destination string and the length of the source string.
        ->User can assume the entire source string was copied, and the resulting concatenated string is fully represented in destination 'buffer'.
   (2)If the concatenation is successful but the source string is truncated due to insufficient space in the destination buffer
        Return value will be the sum of the original length of the destination string and the length of the source string. 
        ->User can get the size of the string required to copy source string into destination buffer. 
   (3)If there is not enough space in the destination buffer to perform any concatenation
        Return value will be dlen + strlen(src), demonstrating the concatenation was not performed due to the memory lack of destination buffer. 
   (4)If the length of the destination buffer is equal or exceeds the size of strlen(src)
        Same as case 3.

    The return value of strlcat indicates rather the concatenation was completed successfully, or the enough space required to complete the concatenation, or
    the memory assgined to destination is not enough to complete the concatenation. 
   */
    if(d_len < size){
        return src_len + d_len;
    }
    else{
        return src_len + size;
    }
}