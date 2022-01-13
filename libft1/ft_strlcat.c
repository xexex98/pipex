/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:05:05 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/16 15:23:24 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	res;

	lendest = 0;
	lensrc = 0;
	res = 0;
	while (dest[lendest])
		lendest++;
	while (src[res])
		res++;
	if (len <= lendest)
		res += len;
	else
		res += lendest;
	while (src[lensrc] && (lendest + 1) < len)
	{
		dest[lendest] = src[lensrc];
		lendest++;
		lensrc++;
	}
	dest[lendest] = '\0';
	return (res);
}
