#include <stddef.h>
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int count;

	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}