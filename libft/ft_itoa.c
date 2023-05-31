#include "libft.h"

static int	ft_num_len(int n)
{
	int len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

char	*ft_itoa(int n)
{
	int		len = ft_num_len(n);
	char	*x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return NULL;
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		x[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		x[len--] = '0' + (n % 10);
		n /= 10;
	}
	return x;
}