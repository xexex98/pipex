/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:45:42 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/14 20:08:51 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	ft_execve(char	*argv, char **env)
{
	char	**bin;
	char	**cmds;
	char	*bincmd;
	char	*slash;
	int		i;

	cmds = ft_split(argv, ' ');
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
			if (execve(bincmd, cmds, env) == -1)
				err(7, NULL);
		}
		free(bincmd);
	}
	free_bin_split(bin);
	err(5, argv);
}

void	pipex(char *argv, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		err(0, NULL);
	pid = fork();
	if (pid == -1)
		err(1, NULL);
	if (pid == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			err(2, NULL);
		ft_execve(argv, env);
	}
	if (pid > 0)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			err(2, NULL);
		waitpid(pid, NULL, 0);
	}
}

void	ft_gnl(int *pipefd, char **argv)
{
	char	*gnl;

	close(pipefd[0]);
	write(1, "heredoc>", 9);
	gnl = get_next_line(0);
	while (gnl)
	{	
		if (ft_strcmp(gnl, argv[2]) == 0)
			exit(EXIT_SUCCESS);
		write(pipefd[1], gnl, ft_strlen(gnl));
		free(gnl);
		write(1, "heredoc>", 9);
		gnl = get_next_line(0);
	}
}

void	ft_heredoc_exe(char **argv)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		err(0, NULL);
	pid = fork();
	if (pid == -1)
		err(1, NULL);
	if (pid == 0)
		ft_gnl(pipefd, argv);
	else if (pid > 0)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			err(2, NULL);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		in;
	int		out;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		out = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		ft_part_1(argc, argv);
	}
	else
	{
		if (argc < 4)
			err(4, NULL);
		i = 2;
		in = open(argv[1], O_RDONLY);
		out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		ft_part_2(in, out);
	}
	while (i < argc - 2)
		pipex(argv[i++], env);
	if (dup2(out, STDOUT_FILENO) == -1)
		err(2, NULL);
	close(out);
	ft_execve(argv[argc - 2], env);
}
