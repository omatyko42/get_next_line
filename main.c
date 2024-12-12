#include <fcntl.h>
#include "get_next_line.h"
#include "stdio.h"
#include <stdlib.h>
/*
int main()
{
	int fd;
	char	*str;

	fd = open("test.txt",O_RDONLY);
	if (fd == -1) {
		printf("Error opening file");
        return 1;
    }
	str = get_next_line(fd);
	if (str)
		printf("%s", str);
	str = get_next_line(fd);
	if (str)
		printf("%s", str);
	free(str);
	close(fd);
	return (0);
}
*/
int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
