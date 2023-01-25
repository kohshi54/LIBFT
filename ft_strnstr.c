#include <stddef.h>
#include "libft.h" // ft_memcmp() ft_strlen()

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (haystack == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ft_strlen(needle) > len)
			return (NULL);
		if (*haystack == *needle)
			if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}