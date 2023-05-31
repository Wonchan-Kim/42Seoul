//ft_putchar_fd
/*
    This function takes in fd as a file descriptor and a character to write. 
    File descriptopr is a process-unique identifier for a file or other input/output resource, such as pipe or network socket. 
    Typically have non-negative integer values, with negative values indicating no value or error conditions. 
    0 - stdin, 1 - stdout, 2 - stderr
    In Unix-like system, fd can refer to any Unix file type named in a file system.  
*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}