#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	write(fd, ft_itoa(n), ft_strlen(ft_itoa(n)));
}