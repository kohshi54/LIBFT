/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:58:22 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 22:15:24 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*head;

	if (!dst && !src)
		return (NULL);
	head = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (head);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	// printf("%p\n", memcpy(NULL, NULL, 1)); // 0x0
	// printf("%p\n", memcpy("abcde", NULL, 1)); // segv
	// printf("%p\n", memcpy(NULL, "abcde", 1)); // segv
	
	// printf("%p\n", ft_memcpy(NULL, NULL, 1)); // 0x0
	// printf("%p\n", memcpy("abcde", NULL, 1)); // segv
	// printf("%p\n", memcpy(NULL, "abcde", 1)); // segv
	return (0);
}