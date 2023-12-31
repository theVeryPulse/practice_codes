/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:55:56 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/19 16:17:59 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	merge(int *l_half, int l_len, int *r_half, int r_len);
static void	cpy_int_ary(int *dst, int *src, int len);
// static void	set_to_zero(int *i, int *r_i, int *l_i);

/* Sorts an int ary with merge sort. Time complexity of O(n*log(n)).

   Pseudo code:
     sort left half
     sort right half
     merge left and right halves 
  
   left half len: (len / 2)
   right half len: (len - len / 2) */
int	*merge_sort(int *ary, int len)
{
	int	*l_half;
	int	*r_half;
	int	l_len;
	int	r_len;

	if (len == 1)
		return (ary);
	l_half = &ary[0];
	r_half = &ary[len / 2];
	l_len = len / 2;
	r_len = len - l_len;
	merge_sort(l_half, l_len);
	merge_sort(r_half, r_len);
	merge(l_half, l_len, r_half, r_len);
	return (ary);
}

/* Merges the sorted left and right halves into a new array, copies the int
   values back into the original array. Each loop, compares the first number in
   left and right halves, cuts that number into the new array.
   
   Stable sort: when left equals to right, left takes precedence. */
static void	merge(int *l_half, int l_len, int *r_half, int r_len)
{
	int	*sorted;
	int	i;
	int	r_i;
	int	l_i;

	sorted = (int *)malloc(sizeof(int) * (l_len + r_len));
	if (!sorted)
		return ;
	i = 0;
	r_i = 0;
	l_i = 0;
	while (i < l_len + r_len)
	{
		if (l_i >= l_len)
			sorted[i++] = r_half[r_i++];
		else if (r_i >= r_len)
			sorted[i++] = l_half[l_i++];
		else if (l_half[l_i] <= r_half[r_i])
			sorted[i++] = l_half[l_i++];
		else
			sorted[i++] = r_half[r_i++];
	}
	cpy_int_ary(l_half, sorted, l_len + r_len);
	free(sorted);
}

/* static void	set_to_zero(int *i, int *r_i, int *l_i)
{
	*i = 0;
	*r_i = 0;
	*l_i = 0;
} */

static void	cpy_int_ary(int *dst, int *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
