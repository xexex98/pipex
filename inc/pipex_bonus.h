/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:39:03 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/14 20:08:38 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

void	ft_execve(char	*argv, char **env);
void	pipex(char *argv, char **env);
void	ft_gnl(int *pipefd, char **argv);
void	ft_heredoc_exe(char **argv);

char	**ft_path(char **env);
void	free_bin_split(char **bin);
int		err(int err, char *cmds);
void	ft_part_1(int argc, char **argv);
void	ft_part_2(int in, int out);

#endif