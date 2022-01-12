/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:39:03 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/12 21:35:42 by mbarra           ###   ########.fr       */
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

char	**ft_path(char **env);
void	free_bin_split(char **bin);
int		err(int err, char *cmds);

#endif