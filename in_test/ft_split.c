/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:36 by juli              #+#    #+#             */
/*   Updated: 2023/11/03 17:26:45 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
/* tested 03/11/2023 */

size_t	get_str_num(char const *s, char d)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
			sum++;
		while (s[i] != d && s[i])
			i++;
	}
	return (sum);
}

char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != c)
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != c)
	{
		out_str[i] = s[i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	**strs;

	total = get_str_num(s, c);
	strs = (char **)malloc((total + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "   ";
	char c = ' ';
	char **output;

	output = ft_split(s, c);
	for (int i = 0; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	return (0);
}
*/