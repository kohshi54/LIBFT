/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:18:58 by kohshi54          #+#    #+#             */
/*   Updated: 2023/01/27 15:01:56 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_element(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i == j)
		{
			i++;
			continue ;
		}
		count++;
		if (s[i] == '\0')
			return (count);
		i++;
	}	
	return (count);
}

static void	*free_all(char **p, size_t i)
{
	size_t	count;

	count = 0;
	while (count < i)
		free(p[count++]);
	free(p);
	return (NULL);
}

char	**my_split(const char *s, char c, char **p, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i == start)
		{
			i++;
			continue ;
		}
		p[j] = malloc(sizeof(char) * (i - start + 1));
		if (!p)
			return (free_all(p, j));
		ft_strlcpy(p[j], &s[start], (i - start + 1));
		j++;
		if (s[i++] == '\0')
			break ;
	}
	p[j] = NULL;
	return (&p[0]);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	start;

	start = 0;
	p = malloc(sizeof(char *) * (count_element(s, c) + 1));
	if (!p)
		return (NULL);
	p = my_split(s, c, p, start);
	if (!p)
		return (NULL);
	return (p);
}
