#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i = 0;
    char *ans;

    ans = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (ans == NULL)
        return NULL;

    while (*s)
    {
        ans[i] = f(i, *s);
        i++;
        s++;
    }
    ans[i] = '\0';

    return ans;
}