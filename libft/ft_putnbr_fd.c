//ft_putnbr_fd
/*
Outputs the integer ’n’ to the given file descriptor.
*/
void ft_putnbr_fd(int n, int fd){
    //possible error:  the int type holds the value from -2147483648~2147483647. if you multiply -1, overflow error occurs. 
    if (n == -2147483648)
        {
                write(fd, "-2147483648", 11);
        }
        else if (n < 0)
        {
                write(fd, "-", 1);
                ft_putnbr_fd(-n, fd);
        }
        else if (n < 10 && n >= 0)
        {
                ft_putchar_fd(n + '0', fd);
        }
        else if (n > 0)
        {
                ft_putnbr_fd(n / 10, fd);
                ft_putchar_fd(n % 10 + '0', fd);
        }
}