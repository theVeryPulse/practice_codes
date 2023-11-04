/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:57:51 by juli              #+#    #+#             */
/*   Updated: 2023/11/04 20:24:10 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* last tested on 04/11/2023 */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((char *)s1)[i] && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str0 = "abcdeF";
	char *str1 = "abcdef";
	int n = 6;
	printf("str0: %s\nstr1: %s\n", str0, str1);
	printf("Should be %d\n", memcmp(str0, str1, n));
	printf("is now    %d\n", ft_memcmp(str0, str1, n));
}
*/
