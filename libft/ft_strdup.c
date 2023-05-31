#include "libft.h"

char *ft_strdup(const char *string){
    int i = 0;
    int j = 0;
    while(string[i] != '\0'){
        i++;
    }
    if(i == 0)
        return NULL;
    char *string_copy = (char*)malloc(sizeof(char) * (i + 1));
    while(string[j] != '\0'){
        string_copy[j] = string[j];
        j++;
    }
    string_copy[j] = '\0';
    return string_copy;
}