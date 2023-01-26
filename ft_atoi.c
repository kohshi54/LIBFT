#include "libft.h"
#include <ctype.h>
#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int ft_atoi(const char *str)
{
	size_t flg;
	long num;

	flg = 0;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flg = 1;
		str++;
	}
	while (isdigit(*str))
	{
		if (flg)
		{
			if (num > (LONG_MIN/10) * -1)
				return ((int)LONG_MIN);
			else if (num == ((LONG_MIN/10) * -1) && (*str - '0') > (LONG_MIN%10)*-1)
				return ((int)LONG_MIN);
		}
		else
		{
			if (num > (LONG_MAX/10))
				return ((int)LONG_MAX);
			else if (num == (LONG_MAX/10) && (*str - '0') > (LONG_MAX%10))
				return ((int)LONG_MAX);
		}
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (flg)
		return ((int)num * (-1));
	else
		return ((int)num);
}