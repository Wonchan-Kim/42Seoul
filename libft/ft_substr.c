#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len){
    char* ans;
    unsigned int i;

    i = 0;
    if(s == NULL)
        return NULL;
    ans = (char*)malloc(sizeof(char) * (len+1)); //len + 1 for nul character
    if(ans == NULL)
        return NULL; 
    while(i < (unsigned int)len){
        ans[i] = s[start + i];
        i++;
    }
    ans[i]='\0';
    return ans;
}