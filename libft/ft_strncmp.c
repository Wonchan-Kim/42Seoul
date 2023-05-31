#include "libft.h"
int ft_strncmp(const char *str1, const char *str2, size_t n) {
    size_t i = 0;
    while (str1[i] && str2[i] && i < n) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        i++;
    }

    if (i == n)
        return 0;
    else
        return (str1[i] > str2[i]) - (str1[i] < str2[i]);
}