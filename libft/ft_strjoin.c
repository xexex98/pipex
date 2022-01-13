/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:46:56 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/15 10:19:33 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	sum = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sum)
		return (NULL);
	while (s1[i] != '\0')
	{
		sum[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		sum[i++] = s2[j++];
	sum[i] = '\0';
	return (sum);
}
