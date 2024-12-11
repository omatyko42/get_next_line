#include <fcntl.h>
#include "get_next_line.h"
#include "stdio.h"

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
	close(fd);
	return (0);
}
