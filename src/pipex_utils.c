/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:21:25 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/11 16:09:59 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
}

char	**ft_path(char	**env)
{
	int		i;
	char	**bin;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	bin = ft_split(env[i] + 5, ':');
	return (bin);
}

void	ft_execve(char **cmds, char **env)
{
	char	**bin;
	char	*bincmd;
	int		i;
	char	*slash;

	i = -1;
	if (ft_strchr(cmds[0], '/') != NULL)
		err(6, cmds[0]);
	bin = ft_path(env);
	while (bin[++i])
	{
		slash = ft_strjoin(bin[i], "/");
		bincmd = ft_strjoin(slash, cmds[0]);
		free(slash);
		if (access(bincmd, F_OK) == 0)
		{
			execve(bincmd, cmds, env);
			exit(0);
		}
		free(bincmd);
	}
	free_bin_split(bin);
	err(5, cmds[0]);
}

int	err(int err, char *cmds)
{
	if (err == 1)
		perror("Pipe");
	if (err == 1)
		perror("Fork");
	if (err == 2)
		perror("Dup2");
	if (err == 3)
		perror("Open");
	if (err == 4)
		write(2, "Invalid argc num!\n", 19);
	if (err == 5)
	{
		write (2, cmds, ft_strlen(cmds));
		write (2, ": command not found\n", 21);
	}
	if (err == 6)
	{
		write (2, cmds, ft_strlen(cmds));
		write (2, ": no such file or directory\n", 29);
	}
	exit(EXIT_FAILURE);
}
