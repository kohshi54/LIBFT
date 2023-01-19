#include <stdlib.h>
#include "libft.h"

int count_byte(char const *s1, char const *set)
{
	size_t count;

	count = 0;
	while (*s1)
	{
		if (ft_strncmp(s1, set, ft_strlen(set)) == 0)
			s1 += ft_strlen(set);
		else
		{
			count++;
			s1++;
		}
	}
	return (count);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *p;
	char *tmp;

	p = malloc(sizeof(char) * count_byte(s1, set) + 1);
	if (!p)
		return (NULL);
	tmp = p;
	while (*s1)
	{
		if (ft_strncmp(s1, set, ft_strlen(set)) == 0)
			s1 += ft_strlen(set);
		else
			*p++ = *s1++;
	}
	*p = '\0';
	return (tmp);
}