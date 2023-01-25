#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *s1_tmp;
	unsigned char *s2_tmp;

	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	while (n--)
	{
		if (*s1_tmp || *s2_tmp)
			if (*s1_tmp != *s2_tmp)
				return (*s1_tmp - *s2_tmp);
		s1_tmp++;
		s2_tmp++;
	}
	return (0);
}