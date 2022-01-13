/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:08:32 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/16 12:54:01 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearr(char **arrstr, int j)
{
	while (j > 0)
	{
		j--;
		free(arrstr[j]);
	}
	free(arrstr);
	return (NULL);
}

static int	ft_worlds_num(char *str, char c)
{
	int	i;
	int	worlds;

	i = 0;
	worlds = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			worlds++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (worlds);
}

static char	*ft_worlds_len(char *word, char *s, int i, int len)
{
	int		j;

	j = 0;
	while (len > 0)
	{
		word[j] = s[i - len];
		j++;
		len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_25(char **arrstr, char *str, char c, int worlds_num)
{
	int					i;
	int					j;
	unsigned int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] != '\0' && j < worlds_num)
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			i++;
			len++;
		}
		arrstr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arrstr)
			return (freearr(arrstr, j));
		ft_worlds_len(arrstr[j], str, i, len);
		len = 0;
		j++;
	}
	arrstr[j] = NULL;
	return (arrstr);
}

char	**ft_split(char *str, char c)
{
	char				**arrstr;
	int					worlds_num;

	if (!str)
		return (NULL);
	worlds_num = ft_worlds_num(str, c);
	arrstr = (char **)malloc(sizeof(char *) * (worlds_num + 1));
	if (!arrstr)
		return (NULL);
	ft_25(arrstr, str, c, worlds_num);
	return (arrstr);
}
