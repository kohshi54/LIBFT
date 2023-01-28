/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:54 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 22:54:30 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0 && (!haystack || !needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ft_strlen(needle) > len)
			return (NULL);
		if (*haystack == *needle)
			if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	// printf("%s\n", strnstr(NULL, NULL, 1)); // segv
// 	// printf("%s\n", strnstr("abcde", NULL, 1)); // segv
// 	// printf("%s\n", strnstr(NULL, "abcde", 1)); // segv
// 	// printf("%s\n", strnstr(NULL, "abcde", 0)); // NULL
// 	// printf("%s\n", strnstr("abcde", NULL, 0)); // NULL
// 	// printf("%s\n", strnstr(NULL, NULL, 0)); // segv

// 	// printf("%s\n", ft_strnstr(NULL, NULL, 1)); // segv
// 	// printf("%s\n", ft_strnstr("abcde", NULL, 1)); // segv
// 	// printf("%s\n", ft_strnstr(NULL, "abcde", 1)); // segv

// 	// printf("%s\n", ft_strnstr("abcde", NULL, 0)); // NULL
// 	// printf("%s\n", ft_strnstr(NULL, "abcde", 0)); // NULL

// 	// printf("%s\n", ft_strnstr(NULL, NULL, 0)); // segvしない？？？
	
// 	return (0);
// }