#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len){
    /*
    It is used to search for the first occurrence of a substring within a given string, limiting the search to a specified number of characters.

    haystack is a pointer to the string in which you want to search for the substring.
    needle is a pointer to the substring you want to find.
    len is the maximum number of characters to search within the haystack string.

    The strnstr function returns a pointer to the first occurrence of the needle substring within the haystack string, limited to len characters. 
    If the substring is not found, it returns NULL.
    */
   size_t needle_len = ft_strlen(needle);

   if(needle_len == 0)
    return (char *)haystack; //empty substring
   size_t i = 0;
   size_t j;
   while(i < len - needle_len){
    j = 0;
    while(j < needle_len && haystack[i+j] == needle[j])
        j++;
    if(j == needle_len)
        return (char *)(haystack+i);
    i++;
   }
    return NULL;
}