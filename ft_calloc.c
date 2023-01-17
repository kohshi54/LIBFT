#include "libft.h"
#include <stdlib.h>
#include <errno.h>

void *ft_calloc(size_t count, size_t size)
{
	void *p;

	p = malloc(count * size);
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}