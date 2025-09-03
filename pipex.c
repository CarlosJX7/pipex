/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:20:41 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/03 16:20:46 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	end(int pid1, int pid2)
{
	int	status;
	int	status2;

	waitpid(pid1, &status, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
	{
		exit(WEXITSTATUS(status2));
	}
	exit(EXIT_FAILURE);
}

void	ft_exec(char *cmd1, char **env)
{
	char	**comandos;
	char	*ruta;

	comandos = ft_split(cmd1, ' ');
	if (!cmd1)
		exit(1);
	ruta = ft_get_path(comandos[0], env);
	if (!ruta)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(comandos[0], 2);
		ft_free_array(comandos);
		exit(127);
	}
	if (execve(ruta, comandos, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(comandos[0], 2);
		ft_free_array(comandos);
		free(ruta);
		exit(127);
	}
}

void	ft_proceso_hijo(char **argv, char **env, int *pipe_fd)
{
	int		fd;
	char	*cmd1;
	char	*fichero;
	int		valor_devuelto;

	valor_devuelto = 0;
	fichero = argv[1];
	cmd1 = argv[2];
	fd = ft_get_fd(fichero, 0);
	if (fd == -1)
		valor_devuelto = 1;
	else
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd);
		ft_exec(cmd1, env);
	}
	exit(valor_devuelto);
}

void	ft_proceso_padre(char **argv, char **env, int *pipe_fd)
{
	int		fd;
	char	*cmd2;

	cmd2 = argv[3];
	fd = ft_get_fd(argv[4], 1);
	if (fd == -1)
	{
		perror("pipex: opening file");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	close(fd);
	ft_exec(cmd2, env);
}

int	main(int argc, char *argv[], char **env)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
		ft_proceso_hijo(argv, env, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		exit(EXIT_FAILURE);
	if (pid2 == 0)
		ft_proceso_padre(argv, env, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	end(pid1, pid2);
}
