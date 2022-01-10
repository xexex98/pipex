/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:21:25 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/10 20:11:10 by mbarra           ###   ########.fr       */
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
	return ;
}

int	err(int err)
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
	if (err == 5)
		write(2, "Cmd not found\n", 15);	
	exit(EXIT_FAILURE);
}
