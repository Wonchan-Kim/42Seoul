#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2){
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int total_len = len1 + len2;
    char * ans = (char*)malloc(sizeof(char)*total_len + 1); //null termination 
    char * tmp = ans; 

    if(ans == NULL)
        return NULL;
    while(*s1 != '\0'){
        *tmp = *s1;
        tmp++;
        s1++;
    }
    while(*s2!= '\0'){
        *tmp = *s2;
        tmp++;
        s2++;
    }
    *tmp = '\0';

    return ans;
}
