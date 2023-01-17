#include "libft.h"

int ft_atoi(const char *str)
{
	int num;
	int neg;

	neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	num = 0;
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (neg * num);
}