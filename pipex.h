/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:34:58 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/03 16:35:01 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

int		ft_get_fd(char *ruta, int modo);
char	*ft_get_path(char *cmd, char **env);
char	*ft_get_env(char *env[], char *variable_entorno);
void	ft_free_array(char **array);
void	ft_error_exit(char **comandos);

#endif
