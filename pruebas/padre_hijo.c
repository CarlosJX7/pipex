#include <stdio.h> 
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	char buffer[100];

	pipe(fd);	
	__pid_t pip = fork();
	if (pip == 0)
	{
		close(fd[0]);
		char *cadena = "Mensaje desde el programa clonado";
		write(fd[1], cadena, strlen(cadena) + 1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		printf("Mensaje recibido en el original >%s<\n", buffer);
		close(fd[0]);
	}
	return 0;
}
