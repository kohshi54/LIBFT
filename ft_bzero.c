#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *uc;

	uc = (unsigned char *) s;
	while (n--)
	{
		*uc = '\0';
		uc++;
	}
}