#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	char *buf = "hello\n";
	char *buf2 = "world\n";
	
	write (1, buf, strlen(buf));
	write (2, buf, strlen(buf));

	exit(0);
}
