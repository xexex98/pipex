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
	argv[4] = "f2";
	in = open(argv[1], O_RDONLY);
	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (in < 0 || out < 0)
		err(3);

	if (pipe(pipefd) == -1)
		err(1);
	dup2(in, 0); //теперь стандартный ВВОД это мой файл, а не консоль.
	dup2(out, 1); //теперь стандартный ВЫВОД это мой файл, а не консоль.
	pid = fork();
	if (pid == -1)
		err(2);
	char *args[] = {"pwd", NULL};

	// родителю возвращается PID процесса-потомка, а потомку возвращается 0
	if (pid == 0)
	{
		//дочерний процесс
		dup2(pipefd[1], 1); //теперь стандартный ВЫВОД сюда запишется то что ВВЕЛИ
		printf("0\n");
		execve("/bin/pwd", args, env);
		
		close(pipefd[0]);
		close(in);
	}
	if (pid > 0)
	{
		//родительский процесс
		dup2(pipefd[0], 0); //теперь стандартный ВЫВОД сюда запишется то что ВВЕЛИ
		printf(">0\n");
		execve("/bin/pwd", args, env);
		access("/bin/pwd", F_OK);
		close(pipefd[1]);
		close(out);
	}
	// char buf[100];

	// dup2(out, 1); //теперь стандартный ВЫВОД это мой файл, а не консоль.
	// read(in, buf, 3);

	// write(out, buf, 3);
	

	return (0);
}
// > ./pipex file1 cmd1 cmd2 file2