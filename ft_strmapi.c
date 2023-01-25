#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *p;
	char *tmp;
	size_t i;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen(s));
	if (!p)
		return (NULL);
	tmp = p;
	while (s[i])
	{
		*p++ = f(i, s[i]);
		i++;
	}
	return (tmp);
}