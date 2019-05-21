#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd1, fd2;

	fd1 = open ("foo", O_RDONLY);
	fd2 = open ("foo2", O_WRONLY);

	ssize_t nread;
	char buf[100];
	while ((nread = read(fd1, buf,100)) > 0)
		write (fd2, buf, nread);
	close (fd1);
	close (fd2);
	exit(0);
}
