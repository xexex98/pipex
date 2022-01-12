/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:21:25 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/12 19:46:53 by mbarra           ###   ########.fr       */
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
	if (err == 7)
		perror("Execve");
	exit(EXIT_FAILURE);
}
