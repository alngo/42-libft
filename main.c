#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "libft.h"

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("./trash/me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (ft_gnl(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, &n, 1);
		free(line);
	}
	close(fd);
	close(fd2);
	child = fork();
	if (child == 0)
	{
		char	*arg[] = {"/usr/bin/diff", NULL, "./trash/me.txt", NULL};

		arg[1] = argv[1];
		execve(arg[0], arg, NULL);
		exit(0);
	}
	else
		wait(NULL); // bad code I know ... but it's not the project
	(void)argc;
	(void)argv;
	return (0);
}
