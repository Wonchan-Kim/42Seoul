#include "libft.h"

//ft_putendl_fd
/*
    Outputs the string 's' to the given file descriptor followed by a new line. 
*/
void ft_putendl_fd(char *s, int fd){
    if(s == NULL)
        return;
    while(*s){
        write(fd, s, 1);
        s++;
    }

    write(fd, '\n', 1);
}
