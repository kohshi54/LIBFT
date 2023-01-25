/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohshi54 <kohshi54@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:18:58 by kohshi54          #+#    #+#             */
/*   Updated: 2023/01/25 19:42:36 by kohshi54         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t count_element(char const *s, char c)
{
	size_t count;
	size_t i;
	size_t j;

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
			continue;
		}
		count++;
		if (s[i] == '\0')
			return (count);
		i++;
	}	
	return (count);
}

static void free_all(char **p, size_t i)
{
	size_t count;

	count = 0;
	while (count < i)
		free(p[count++]);
	free(p);
}

char **ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t start;
	char **p;

	i = 0;
	j = 0;
	p = malloc(sizeof(char*) * (count_element(s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i == start)
		{
			i++;
			continue;
		}
		p[j] = malloc(sizeof(char) * (i - start + 1));
		if (!p)
		{
			free_all(p, j);
			return (NULL);
		}
		ft_strlcpy(p[j], &s[start], (i - start + 1));
		j++;
		if (s[i] == '\0')
			break;
		i++;
	}
	p[j] = NULL;
	return (p);
}