/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:52:46 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/27 11:53:04 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	count;

	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}
