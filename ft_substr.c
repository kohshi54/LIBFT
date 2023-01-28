/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:48:06 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 20:46:14 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*head;

	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	head = p;
	while (start--)
		s++;
	while (len-- && *s)
		*p++ = *s++;
	*p = '\0';
	return (head);
}
