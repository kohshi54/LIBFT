/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:02:25 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 19:41:55 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_digit(long n)
{
	size_t	count;

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

char	*ft_itoa(int n)
{
	char	*num;
	size_t	count;

	if (n == -2147483648)
	{
		num = malloc(sizeof(char) * (11 + 1));
		ft_strlcpy(num, "-2147483648", 12);
		return (num);
	}
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
	num[count] = (n % 10) + '0';
	return (num);
}
