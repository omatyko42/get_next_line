#include <fcntl.h>
#include "get_next_line_bonus.h"
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
	int		fd, fd2;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd);
	printf("%s", line);
	free(line);
	line = get_next_line_bonus(fd2);
	printf("%s", line);
	free(line);
	
	close(fd);
	close(fd2);
	return (0);
}
