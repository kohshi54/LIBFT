#include <stddef.h>
#include <stdlib.h>

size_t count_digit(int n)
{
	size_t count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}
char *ft_itoa(int n)
{
	char *num;
	size_t count;

	if (n == -2147483648)
		return ("-2147483648");
	count = count_digit(n);
	num = malloc(sizeof(char) * (count + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	num[count--] = '\0';
	while (n > 9)
	{
		num[count--] = (n % 10) + '0';
		n /= 10;
	}
	num[count] = (n % 10) +'0';
	return (num);
}