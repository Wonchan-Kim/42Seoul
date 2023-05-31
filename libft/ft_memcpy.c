#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n){
    if(dest == NULL || src == NULL)
        return NULL;
    size_t i = 0;
    /*consideration : 
                        1. memory overlap : 
+++++++++++++++++++++++++++++++
| 'a' | 'b' | 'c' | 'd' | 'e' |         suppose given src is a array with size of 5, and dest was assigned as 0x102 with n assigned with 3.
+++++++++++++++++++++++++++++++         

 0x100 0x101 0x102 0x103 0x104           

 if we traverse while loop from the start point, the memory overlap will happen, and result in overwring original src.

 +++++++++++++++++++++++++++++++
| 'a' | 'b' | 'a' | 'b' | 'a' |     (0x104 should be 'c' if memcpy function works without error)
+++++++++++++++++++++++++++++++
 0x100 0x101 0x102 0x103 0x104

                        Therfore, we should compare if the memory might collide during traversing, with the code 
                        if(s < d && s + n > d)
                        In this case, memory overlap could be avoided with copying in reverse order. 
    */

   unsigned char* destination = (unsigned char*) dest;
   unsigned char* source = (unsigned char*)src;
    if(destination > source && source + n > destination){
        i = n;
        while(i > 0){
            destination[i-1] = source[i-1]; 
            i--;
        }
    }
    else{
        while(i < n){
            destination[i] = source[i];
            i++;
        }
    }
    return (void*)dest;
}
