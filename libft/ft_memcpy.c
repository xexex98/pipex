/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:28:47 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/14 17:54:41 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;
	size_t			i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	p = (unsigned char *) dest;
	c = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p[i] = c[i];
		i++;
	}
	return (dest);
}
