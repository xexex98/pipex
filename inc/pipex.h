/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:39:03 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/10 15:29:26 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PIPEX_H
# define _PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char	*str);
char	*ft_strjoin(char const *s1, char const	*s2);
char	**freearr(char **arrstr, int j);
int		ft_worlds_num(char *str, char c);
char	*ft_worlds_len(char *word, char *s, int i, int len);
char	**ft_25(char **arrstr, char *str, char c, int worlds_num);
char	**ft_split(char *str, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *dest, const char *src, size_t n);
void	free_bin_split(char **bin);
int		err(int err);
void	parent_pid(int in, int *pipefd, char **argv, char **env);
void	child_pid(int out, int *pipefd, char **argv, char **env);
void	ft_execve(char **cmds, char **env);



#endif
