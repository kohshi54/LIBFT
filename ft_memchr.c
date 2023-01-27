/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:59:11 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/27 11:59:22 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == uc)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
