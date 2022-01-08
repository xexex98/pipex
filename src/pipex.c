// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/01/07 17:38:25 by mbarra            #+#    #+#             */
// /*   Updated: 2022/01/08 21:45:13 by mbarra           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../inc/pipex.h"

int err(int err)
{
	if (err == 1)
		perror("Pipe: ");
	if (err == 1)
		perror("Fork: ");
	if (err == 2)
		perror("Dup2: ");
	if (err == 3)
		perror("Open: ");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[], char **env)
{
	(void)argc; //!
	pid_t pid;
	int pipefd[2];
	int in;
	int out;
	
	argv[1] = "f1";
	argv[2] = "f2";
	in = open(argv[1], O_RDONLY);
	out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (in < 0 || out < 0)
		err(3);
	if (pipe(pipefd) == -1)
		err(1);
	pid = fork();
	if (pid == -1)
		err(2);

	// char *args[] = {"ls", "-l", "-a", NULL};
	// execve("/bin/ls", args, env);
	printf ("hi\n");
	dup2(in, 0);
	dup2(out, 1);
	write(out, "Hi\n", 3);
	return (0);
}
