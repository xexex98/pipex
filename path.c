/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:37:04 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/09 19:08:04 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pipex.h"

static size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}

static char	*ft_strnstr(const char *dest, const char *src, size_t n)
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

void	free_bin_split(char **bin)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (bin[size])
		size++;
	while (i < size)
		free(bin[i++]);
	free(bin);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	char	**bin;
	char	*binpath;
	char	*slash;
	int		i;
	char	*cmd;
	char	*cmds;
	char	*args[] = {"pwd", NULL};

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	bin = ft_split(env[i] + 5, ':');
	i = -1;
	//првоерка команды на /
	while (bin[++i])
	{	
		cmds = "pwd";
		cmd = ft_split(cmds, ' ');
		slash = ft_strjoin(bin[i], "/");
		binpath = ft_strjoin(slash, cmds);
		free(slash);
		if (access(binpath, F_OK) == 0)
		{
			free_bin_split(bin);
			execve(binpath, args, env);
			return (0);
		}
		free(binpath);
	}
	free_bin_split(bin);
	return (0);
}
