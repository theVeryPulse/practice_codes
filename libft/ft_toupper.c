/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:27 by juli              #+#    #+#             */
/*   Updated: 2023/11/04 19:33:25 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* last tested on 04/11/2023 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	for (int i = 'a'; i <= 'z'; i++)
		printf("%c to upper: %c\n", i, ft_toupper(i));
}
*/
