/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:39:40 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/14 17:09:51 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*str;
	unsigned int	mem;

	mem = nmemb * size;
	str = malloc(mem);
	if (!str)
		return (NULL);
	ft_memset(str, '\0', mem);
	return (str);
}
