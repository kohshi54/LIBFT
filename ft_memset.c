#include "ft_header.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *uc;

	uc = (unsigned char *) b;
	while (len)
	{
		*uc = c;
		uc++;
		len--;
	}
	return (b);
}