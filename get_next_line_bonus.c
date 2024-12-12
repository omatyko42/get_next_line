#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define MAX_FD 1024

static char *get_fd_buffer(int fd)
{
    static char *fd_buffers[MAX_FD] = {NULL};
    if (fd < 0 || fd >= MAX_FD)
        return (NULL);
    if (!fd_buffers[fd])
        fd_buffers[fd] = ft_strdup("");
    return (fd_buffers[fd]);
}

static char *ft_strjoin(const char *s1, const char *s2)
{
    size_t i, j;
    char *str;

    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
        str[i++] = s1[i];
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}

static char *extract_line(char **buffer)
{
    char *line;
    size_t i;
    char *new_buffer;

    if (!*buffer || !**buffer)
        return (NULL);
    i = 0;
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    line[i] = '\0';
    if ((*buffer)[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    new_buffer = ft_strdup(*buffer + i);
    free(*buffer);
    *buffer = new_buffer;
    return (line);
}

static int read_to_buffer(int fd, char **buffer)
{
    char read_buff[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *temp;

    bytes_read = read(fd, read_buff, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (bytes_read);
    read_buff[bytes_read] = '\0';
    temp = *buffer;
    *buffer = ft_strjoin(*buffer, read_buff);
    free(temp);
    return (bytes_read);
}

char *get_next_line(int fd)
{
    char *line;
    int bytes_read;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = get_fd_buffer(fd); 
    bytes_read = 1;
    while (!ft_strichr(buffer, '\n') && bytes_read > 0)
        bytes_read = read_to_buffer(fd, &buffer);

    if (bytes_read < 0)
    {
        free(buffer);
        return (NULL);
    }

    line = extract_line(&buffer);

    if (bytes_read == 0)
    {
        free(buffer);
    }

    return (line);
}
