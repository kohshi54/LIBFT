#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>

static bool overflow_checker(size_t count, size_t size)
{
	if (count * size < (count * (size - 1)))
		return (1);
	return (0);
}

void *ft_calloc(size_t count, size_t size)
{
	void *p;

	if (!count || !size)
		count = 0;
	else if (overflow_checker(count, size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(p, count * size);
	// printf("count: %lu\n", count);
	// printf("size: %lu\n", count);
	// printf("count * size: %lu\n", count * size);
	// if (ft_bzero(p, count * size))
		// return (NULL);
	return (p);
}

// int main(void)
// {
// 	printf("%s\n", (char *)calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("%s\n", (char *)ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	return (0);
// }