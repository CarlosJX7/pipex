/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:32:10 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/03 16:32:12 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_exit(char **comandos)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(comandos[0], 2);
	ft_free_array(comandos);
}

int	ft_get_fd(char *ruta, int modo)
{
	int	fd;

	fd = -1;
	if (modo == 0)
		fd = open(ruta, O_RDONLY);
	if (modo == 1)
		fd = open(ruta, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd == -1)
	{
		perror("pipex: error opening file");
		return (-1);
	}
	return (fd);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
	{
		return ;
	}
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_get_env(char *env[], char *variable_entorno)
{
	int		i;
	int		j;
	char	*cadena;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		cadena = ft_substr(env[i], 0, j);
		if (ft_strncmp(cadena, variable_entorno, ft_strlen(cadena)) == 0)
		{
			free(cadena);
			return (env[i] + j + 1);
		}
		free(cadena);
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**rutas_array;
	char	**comandos;
	char	*ruta_actual;
	char	*ejecutable;

	rutas_array = ft_split(ft_get_env(env, "PATH"), ':');
	comandos = ft_split(cmd, ' ');
	i = 0;
	while (rutas_array[i])
	{
		ruta_actual = ft_strjoin(rutas_array[i], "/");
		ejecutable = ft_strjoin(ruta_actual, comandos[0]);
		free(ruta_actual);
		if (access(ejecutable, F_OK | X_OK) == 0)
		{
			ft_free_array(comandos);
			return (ejecutable);
		}
		free(ejecutable);
		i++;
	}
	ft_free_array(rutas_array);
	ft_free_array(comandos);
	return (NULL);
}
