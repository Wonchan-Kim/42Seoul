#include "libft.h"

int ft_atoi(const char *str){
    /*
    The function takes a pointer to a null-terminated string str as its argument and returns the converted int value. 
    It performs the following steps to convert the string:

    Skips any leading white space characters (spaces, tabs, newlines, etc.).
    Determines the sign of the number based on the presence of a leading positive ('+') or negative ('-') sign character.
    Converts the remaining characters in the string to an integer until a non-digit character is encountered or the end of the string is reached.
    Returns the converted int value.
    
    48~57 is the ascii code assigned for 0~9 value each.
    */
    int sign = 1;
    int ans = 0;
    int i = 0;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        ans = ans * 10 + (str[i] - '0');
        i++;
    }

    return ans * sign;
}