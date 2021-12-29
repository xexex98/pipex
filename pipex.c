/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:23:40 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/29 22:23:40 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char	*argv[])
{
	if (argc == 5)
	{
		int	fd1;
		int	fd2;

		fd1 = 0;
		fd2 = 0;
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[4], O_RDONLY);
		if (fd1 < 0 || fd2 < 0)
			perror("Error ");
	}
	return (0);
}