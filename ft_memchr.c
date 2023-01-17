#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char uc;

	uc = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == uc)
			return ((void *)s);
		s++;
	}
	return (NULL);
}