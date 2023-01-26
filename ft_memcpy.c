#include <stddef.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	void *tmp;

	tmp = dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (tmp);
}