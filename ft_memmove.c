#include <stddef.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	void *tmp;

	tmp = dst;
	if (src >= dst)
		while(len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	else
		while(len--)
		{
			dst += len;
			src += len;
			*(unsigned char*)dst-- = *(unsigned char*)src--;
		}
	return (tmp);
}