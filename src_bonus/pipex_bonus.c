/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:42:11 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/11 16:13:50 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_pid(int in, int *pipefd, char **argv, char **env)
{
	char	**cmds;

	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(in, STDIN_FILENO);
	cmds = ft_split(argv[2], ' ');
	ft_execve(cmds, env);
}

void	parent_pid(int out, int *pipefd, char **argv, char **env)
{
	char	**cmds;

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(out, STDOUT_FILENO);
	cmds = ft_split(argv[3], ' ');
	ft_execve(cmds, env);
}

void	pipex(int in, int out, char **argv, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		err(1, NULL);
	pid = fork();
	if (pid == -1)
		err(2, NULL);
	if (pid > 0)
		parent_pid(out, pipefd, argv, env);
	else if (pid == 0)
		child_pid(in, pipefd, argv, env);
}

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;

	if (argc != 5)
		err(4, NULL);
	in = open(argv[1], O_RDONLY);
	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (in < 0 || out < 0)
		err(3, NULL);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	pipex(in, out, argv, env);
	return (EXIT_SUCCESS);
}
