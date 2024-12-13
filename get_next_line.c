/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/13 11:36:44 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	
	*p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	
	*ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;
	
	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t i;
	size_t	len1;
	char	*str;
	
	len1 = ft_strlen(s1), len2 = ft_strlen(s2);
	*str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while(i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		str[len1 + i] = s2[i];
		i++;
	}
	str[len1 + len2] = '\0';
	return (str);
}

int	ft_strichr(const char *s, int c)
{
	int i;
	
	if (!s)
		return (-1);
	i = 0;
	while(s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (c == '\0' ? ft_strlen(s) : -1);
}

char	*extract_line(char **storage, int newline_index)
{
	char	*line;
	char	*new_storage;
	int i;
	
	*line = ft_calloc(newline_index + 2, 1);
	*new_storage = ft_calloc(ft_strlen(*storage) - newline_index, 1);
	if (!line || !new_storage)
		return (free(line), free(new_storage), NULL);
	i = 0;
	while(i <= newline_index)
	{
		line[i] = (*storage)[i];
		i++;
	}
	i = 0;
	while ((*storage)[newline_index + 1 + i])
	{
		new_storage[i] = (*storage)[newline_index + 1 + i];
		i++;
	}
	free(*storage);
	*storage = new_storage;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	int			newline_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((newline_index = ft_strichr(storage, '\n')) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		char *temp = ft_strjoin(storage, buffer);
		free(storage);
		storage = temp;
	}
	if (newline_index >= 0)
		return (extract_line(&storage, newline_index));
	char *line = storage;
	storage = NULL;
	return (line);
}
