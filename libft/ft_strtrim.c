#include "libft.h"

char *ft_strtrim(char const *s1, char const *set){
    //set is the group of the letters that must be removed from the s1.
    // abcd b
    // get start position & end position for trim
    if(set == NULL || s1 == NULL)
        return NULL;
    
    size_t len = ft_strlen(s1);
    size_t s_pos = 0;
    size_t e_pos = len - 1;

    while(s_pos < len && ft_strchr(set, s1[s_pos]) != NULL)
        s_pos++;
    while(e_pos > s_pos && ft_strchr(set, s1[e_pos]) != NULL)
        e_pos--;

    size_t ans_len = (e_pos >= s_pos) ? (e_pos - s_pos + 1) : 0;
    char* ans = malloc(ans_len + 1);
    if(ans == NULL)
        return NULL;
    
    size_t copied_len = strlcpy(ans, s1 + s_pos, ans_len + 1);
    return ans;
}