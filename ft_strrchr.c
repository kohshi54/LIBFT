/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:24 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/27 11:50:45 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	a;

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
