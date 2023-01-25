#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
	char *tmp;
	char a;

	tmp = NULL;
	a = (char) c;
	while (*s)
	{
		if (*s == a)
			tmp = (char *)s;
		s++;
	}
	if (*s == a)
		tmp = (char *)s;
	return (tmp);
}