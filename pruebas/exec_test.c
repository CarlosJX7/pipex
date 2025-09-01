#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);
	__pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execlp("ls", "ls", NULL);
		perror("execlp");
		exit(1);
	}else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execlp("wc", "wc", "-l", NULL);
		perror("execlp");
		exit(1);
	}
	return 0;
}
