#include "ft_header.h"

size_t ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}