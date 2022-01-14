/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:21:25 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/14 20:29:58 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	**ft_path(char **env)
{
	char	**bin;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	bin = ft_split(env[i] + 5, ':');
	return (bin);
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
}

int	err(int err, char *cmds)
{
	if (err == 0)
		perror("Pipe");
	if (err == 1)
		perror("Fork");
	if (err == 2)
		perror("Dup2");
	if (err == 3)
		perror("Open");
	if (err == 4)
		write(2, "./pipex_bonus <file1> <cmd> <cmd1> ... <cmdn> <file2>\n", 55);
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
	if (err == 7)
		perror("Execve");
	if (err == 8)
		write (2, "./pipex_bonus here_doc <LIMITER> <cmd> <cmd1> <file>\n", 54);
	exit(EXIT_FAILURE);
}

void	ft_part_1(int argc, char **argv)
{
	if (argc < 6)
		err(8, NULL);
	ft_heredoc_exe(argv);
}

void	ft_part_2(int in, int out)
{
	if (in < 0 || out < 0)
		err(3, NULL);
	if (dup2(in, STDIN_FILENO) == -1)
		err(2, NULL);
	close(in);
}
