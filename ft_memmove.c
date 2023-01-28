/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:57:18 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/28 22:17:06 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*head;

	if (!dst && !src)
		return (NULL);
	head = dst;
	if (src >= dst)
	{
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	return (head);
}


// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	printf("%p\n", memmove(NULL, NULL, 1));
// 	printf("%p\n", ft_memmove(NULL, NULL, 1));
// 	return (0);
// }