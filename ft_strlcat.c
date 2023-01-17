#include <stddef.h>
#include "libft.h"

size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t count;

	count = ft_strlen(dst) + ft_strlen(src);
	if (dstsize == 0 || ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	dstsize = dstsize - ft_strlen(dst);
	while (*dst)
		dst++;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}