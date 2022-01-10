/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:42:11 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/10 17:14:08 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

size_t	ft_strlen(const char	*str)
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

char	**freearr(char **arrstr, int j)
{
	while (j > 0)
	{
		j--;
		free(arrstr[j]);
	}
	free(arrstr);
	return (NULL);
}

int	ft_worlds_num(char *str, char c)
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

char	*ft_worlds_len(char *word, char *s, int i, int len)
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

char	**ft_25(char **arrstr, char *str, char c, int worlds_num)
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
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

int err(int err)
{
	if (err == 1)
		perror("Pipe: ");
	if (err == 1)
		perror("Fork: ");
	if (err == 2)
		perror("Dup2: ");
	if (err == 3)
		perror("Open: ");
	if (err == 4)
		printf("Invalid argc num!\n");
	exit(EXIT_FAILURE);
}

void	ft_execve(char **cmds, char **env)
{
	char	**bin;
	char	*bincmd;
	int		i;
	char	*slash;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	bin = ft_split(env[i] + 5, ':');
	i = -1;
	while (bin[++i])
	{
		slash = ft_strjoin(bin[i], "/");
		bincmd = ft_strjoin(slash, cmds[0]);
		free(slash);
		if (access(bincmd, F_OK) == 0)
		{
			free_bin_split(bin);
			execve(bincmd, cmds, env);
			exit(0);
		}
		free(bincmd);
	}
	free_bin_split(cmds);
	free_bin_split(bin);
	exit(1);
}

void	pipex(int in, int out, char **argv, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		err(1);
	pid = fork();
	if (pid == -1)
		err(2);
	if (pid > 0)
		parent_pid(out, pipefd, argv, env);
	else if (pid == 0)
		child_pid(in, pipefd, argv, env);
}

void	parent_pid(int out, int *pipefd, char **argv, char **env)
{
	char	**cmds;

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(pipefd[0]);
	close(out);
	cmds = ft_split(argv[3], ' ');
	ft_execve(cmds, env);
}

void	child_pid(int in, int *pipefd, char **argv, char **env)
{
	char	**cmds;

	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	cmds = ft_split(argv[2], ' ');
	ft_execve(cmds, env);
}

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;

	if (argc != 5)
		err(4);
	in = open(argv[1], O_RDONLY);
	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (in < 0 || out < 0)
		err(3);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	
	pipex(in, out, argv, env);
	return (0);
}