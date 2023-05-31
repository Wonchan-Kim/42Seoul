void ft_bzero(void *s, size_t n){
    int i = 0;
    while(i < n){
        (unsigned char)s[i] = 0; // do you have to explicitly cast s[i] to unsigned char or not? No, the s is set with void* datatype,
                                 // therefore the compiler does not know the exact type of the elements in the memory block. 
                                 // difference between bzero and memset is  memset expects an int value that will be cast to unsigned char explicitly, 
                                 // while bzero treats the memory block as a sequence of bytes without the need for an explicit cast since the type of s is void*.
                                 // it treats the memory block as a sequence of bytes regardless of the underlying data type.

        i++;
    }
    /*
    The reason why the data type of s[i] should be the unsigned char is, the size of other data type could be differnt dependent on the system architecture.
    for example, the size of int could be differ from 16 bits to 32 bits. However, unsigned char is always the 1 byte.
    The purpose of bzero function is used to set a block of memory to zero, which means each byte in the block must be set 0.
    Note that unsigned char is used to alter 'byte' regardelss of the system.
    */
}