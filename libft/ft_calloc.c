#include "libft.h"

void *ft_calloc(size_t num, size_t size) {
    // Calculate the total size required
    size_t total_size = num * size;

    // Allocate memory using malloc
    void *ptr = malloc(total_size);

    // Check if memory allocation was successful
    if (ptr != NULL) {
        // Clear the allocated memory by setting all bytes to zero
        // using the memset function from the string.h header
        memset(ptr, 0, total_size);
    }

    return ptr;
}