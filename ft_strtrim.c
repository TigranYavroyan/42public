/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:31:08 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/28 18:15:13 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_move_ptrs(char **left, char **right, char const *set);
static char	*_allocate_null(void);
static char	*_allocate(char const *src, size_t const dstsize);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left;
	char	*right;

	if (!s1 || !set)
		return (NULL);
	left = (char *)s1;
	right = ((char *)s1) + ft_strlen(s1) - 1;
	_move_ptrs(&left, &right, set);
	if (left > right)
		return (_allocate_null());
	return (_allocate(left, right - left + 2));
}

static	void	_move_ptrs(char **left, char **right, char const *set)
{
	while (ft_strchr(set, **left))
		++(*left);
	while (ft_strchr(set, **right))
		--(*right);
}

static char	*_allocate_null(void)
{
	char	*dst;

	dst = (char *)malloc(1);
	*dst = '\0';
	return (dst);
}

static	char	*_allocate(char const *src, size_t const dstsize)
{
	char	*dst;

	dst = (char *)malloc(dstsize);
	if (dst)
		ft_strlcpy(dst, src, dstsize);
	return (dst);
}
