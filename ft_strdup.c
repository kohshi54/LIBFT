#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char *ft_strdup(const char *s1)
{
	char *p;

	p = malloc(sizeof(char) * ft_strlen(s1));
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}