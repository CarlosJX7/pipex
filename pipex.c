#include "pipex.h"

void ft_exec(char *cmd1, char **env)
{
	char **comandos;
	char *ruta;

	comandos= ft_split(cmd1, ' ');
	ruta = ft_get_path(comandos[0], env);	
	if (execve(ruta, comandos, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(comandos[0], 2);
		ft_free_array(comandos);
		exit(0);
	}
}

void ft_proceso_hijo(char **argv, char **env, int *pipe_fd)
{
	int fd;
	char *cmd1;
	char *fichero;

	fichero = argv[1];
	cmd1 = argv[2];
	fd = ft_get_fd(fichero, 0);
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	ft_exec(cmd1, env);
}

void ft_proceso_padre(char **argv, char **env, int *pipe_fd)
{
	int fd;
	char *cmd2;

	cmd2 = argv[3];
	fd = ft_get_fd(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	ft_exec(cmd2, env);
}

int main(int argc, char *argv[], char **env)
{
	int pipe_fd[2];
	pid_t pid;

	if (argc != 5)
		exit(0);
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		ft_proceso_hijo(argv, env, pipe_fd);	
	ft_proceso_padre(argv, env, pipe_fd);
}
