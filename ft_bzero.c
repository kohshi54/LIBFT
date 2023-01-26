#include "libft.h"
#include <stdio.h>
void ft_bzero(void *s, size_t n)
{
	unsigned char *uc;

	uc = (unsigned char *) s;
	while (n--)
	{
		*uc = '\0'; // what is the difference between '\0' and 0 and NULL???
		uc++;
	}
}