#include <stddef.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	void *tmp;

	tmp = dst;
	if (src >= dst)
		while(len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char*)dst-- = *(unsigned char*)src--;
	}
	return (tmp);
}