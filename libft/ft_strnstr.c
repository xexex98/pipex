/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:39:08 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/17 15:41:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	if (!src[0])
		return ((char *)dest);
	i = 0;
	len = ft_strlen((char *)src);
	while (dest[i] && n-- >= len)
	{
		if (dest[i] == src[0] && ft_memcmp(&dest[i], src, len) == 0)
			return ((char *)&dest[i]);
		i++;
	}
	return (NULL);
}
