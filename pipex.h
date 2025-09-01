#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

int ft_get_fd(char *ruta, int modo);
char	*ft_get_path(char *cmd, char **env);
char *ft_get_env(char *env[], char *variable_entorno);
void ft_free_array(char **array);
#endif