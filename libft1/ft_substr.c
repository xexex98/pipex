/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:41:04 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/13 15:12:05 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*copy;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			copy[j] = s[i];
			j++;
		}
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
