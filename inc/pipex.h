/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:39:03 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/11 16:16:20 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

void	child_pid(int out, int *pipefd, char **argv, char **env);
void	parent_pid(int in, int *pipefd, char **argv, char **env);
void	pipex(int in, int out, char **argv, char **env);

void	free_bin_split(char **bin);
char	**ft_path(char	**env);
void	ft_execve(char **cmds, char **env);
int		err(int err, char *cmds);

#endif