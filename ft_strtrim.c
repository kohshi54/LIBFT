/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:48:42 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 19:22:53 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

static bool	check(char s1, char const *set)
{
	while (*set)
		if (s1 == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*p;

	// if (ft_strlen(set) == 0)
	// 	return ((char *)s1);
	i = 0;
	while (check(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (check(s1[j], set) && (i < j))
		j--;
	p = malloc(sizeof(char) * (j - i + 2));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s1[i], (j - i + 2));
	return (p);
}
