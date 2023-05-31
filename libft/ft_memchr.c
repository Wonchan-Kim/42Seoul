#include "libft.h"

void *ft_memchr(const void *ptr, int value, size_t num){
    /*
    ptr: A pointer to the block of memory to be searched.
    value: The byte value to be searched for.
    num: The number of bytes to search within the memory block.
    
    The memchr function in C is used to search for a specific byte value within a block of memory. 
    It allows you to perform a byte-level search in a given memory range, looking for a particular byte value.

    *******Question? Why does all function dealing with bytes take the parameter as 'int type', not 'char' type?
        1. Range of char type can vary depending on the implementation as it can be either signed or unsigned. By using int, both negative and positive
            values could be handled easily.
        2. Int allows function to handle EOF, usually defined as -1.
        3. int provides a wider range and ensures compatibility across different platforms and implemantations.


        The memchr function is primarily used for searching a block of memory for a specific byte value, typically within the range of 0 to 255. 
        */

   size_t i = 0;
   const unsigned char* p = ptr;
   while(i < num){
    if(p[i] == (unsigned char)value)  //unsigned char used to handle full range of byte values in a consistent and portable manner. 
        return (void*)(p+i);
    i++;
   }
   return NULL;
}

/*
#include <stdio.h>

int main() {
    unsigned char buffer[4] = {0xFF, 0x80, 0x00, 0x7F};

    // Using unsigned char
    unsigned char* p1 = (unsigned char*)buffer;
    if (p1[0] == 0xFF) {
        printf("Unsigned char comparison: Match found!\n");
    } else {
        printf("Unsigned char comparison: No match.\n");
    }

    // Using char
    char* p2 = (char*)buffer;
    if (p2[0] == 0xFF) {
        printf("Char comparison: Match found!\n");
    } else {
        printf("Char comparison: No match.\n");
    }

    return 0;
}

When using unsigned char and performing the comparison (p1[0] == 0xFF), it evaluates to true because the comparison is performed in the range of 0 to 255, 
which covers the full range of possible byte values.

However, when using char and performing the comparison (p2[0] == 0xFF), it may evaluate to false. 
This is because the char type is signed on some platforms, and the value 0xFF is interpreted as -1 when it is sign-extended. 
So the comparison becomes (char)-1 == (char)-1, which evaluates to true. 
But if the value in the array were changed to 0x80 (which is negative when interpreted as a signed char), the comparison would evaluate to false, causing unexpected results.

In case of 0x80(128) is converted into -1, so "No Match" is resulted. 
*/