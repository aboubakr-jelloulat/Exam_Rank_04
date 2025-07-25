#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;



	int fd[2];
	pipe(fd);


	
	if (type == 'r')
	{
		if (fork() == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		if (fork() == 0)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[0]);
		return (fd[1]);
	}
	return -1;
}

int main() 
{
    printf("fd : %d\n", ft_popen("ls", (char *const[]){"ls", NULL}, 'r'));
    printf("fd : %d\n", ft_popen("ls", (char *const[]){"ls", NULL}, 'w'));
    // while(1){}
}
