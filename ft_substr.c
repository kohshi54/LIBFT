#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p;
	char *tmp;

	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	tmp = p;
	while (start--)
		s++;
	while (len-- && *s)
		*p++ = *s++;
	*p = '\0';
	return (tmp);
}