#include "libft.h"

int memcmp(const void *ptr1, const void *ptr2, size_t num){
    /*
    ptr1 and ptr2 are the pointers to the memory block to be compared
    num is the number of bytes to be compared
    If the memory blocks are equal, it returns 0.
    if ptr1 is greater than ptr2 it returns a positive value.
    if ptr2 is greater than ptr1 it returns a negative value.
    */
   const unsigned char* pointer1 = (const unsigned char*) ptr1; //unsigned char used to compare the byte values. 
   const unsigned char* pointer2 = (const unsigned char*) ptr2;
   size_t i = 0;
   while(pointer1[i] && pointer2[i] && i < num){
    if(pointer1[i] > pointer2[i])
        return 1;
    else if(pointer1[i] < pointer2[i])
        return -1;
    i++;
   }
   return 0;
}