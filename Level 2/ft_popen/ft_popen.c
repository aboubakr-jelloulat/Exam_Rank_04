#include <unistd.h>
#include <stdlib.h>


static int ReadMode(const char *file, char *const argv[], int fds[2])
{
	pid_t	pid = fork();
	if (pid == -1)
		return -1;
	
	if (pid == 0)
	{
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		execvp(file, argv);
		exit(-1);
	}
	close(fds[1]);
	return (fds[0]);
}

static int WriteMode(const char *file, char *const argv[], int fds[2])
{
	pid_t	pid = fork();
	if (pid == -1)
		return -1;
	
	if (pid == 0)
	{
		dup2(fds[0], 0);
		close(fds[1]);
		close(fds[0]);
		execvp(file, argv);
		exit(-1);         // becomes exit(255)
	}
	close(fds[0]);
	return (fds[1]);

}

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	
	int fds[2];
	if (pipe(fds) == -1)
		return -1;
	
	if (type == 'r')
		return ReadMode(file, argv, fds);
	else
		return WriteMode(file, argv, fds);

	return -1;
}

int main(void)
{
	char buffer[1024];
	int bytes;

	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'w');

	while ((bytes = read(fd, buffer, sizeof(buffer) - 1)))
	{
		buffer[bytes] = '\0';
		write(1, buffer, bytes);
	}

	

	close (fd);

	return 0;
}
