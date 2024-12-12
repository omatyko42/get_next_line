/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/13 00:30:36 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1 = ft_strlen(s1), len2 = ft_strlen(s2);
	char	*str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	for (size_t i = 0; i < len1; i++)
		str[i] = s1[i];
	for (size_t i = 0; i < len2; i++)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	return (str);
}

int	ft_strichr(const char *s, int c)
{
	if (!s)
		return (-1);
	for (int i = 0; s[i]; i++)
		if (s[i] == (char)c)
			return (i);
	return (c == '\0' ? ft_strlen(s) : -1);
}

char	*extract_line(char **storage, int newline_index)
{
	char	*line = ft_calloc(newline_index + 2, 1);
	char	*new_storage = ft_calloc(ft_strlen(*storage) - newline_index, 1);
	if (!line || !new_storage)
		return (free(line), free(new_storage), NULL);
	for (int i = 0; i <= newline_index; i++)
		line[i] = (*storage)[i];
	for (size_t i = 0; (*storage)[newline_index + 1 + i]; i++)
		new_storage[i] = (*storage)[newline_index + 1 + i];
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
