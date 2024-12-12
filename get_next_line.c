/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/12 16:56:50 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*(p++) = 0;
		n--;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	bytes;

	bytes = count * size;
	if (size != 0 && bytes / size != count)
		return (NULL);
	ptr = (void *)malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}


char *ft_read_fd(int fd)
{
	char read_buff[BUFFER_SIZE+1];
	int bytes_read;
	char	*res_buff;
		
	res_buff = (char *) ft_calloc(1,1);
	bytes_read = 1;
	while (bytes_read || ft_strichr(res_buff, '\n'))
	{
		bytes_read = read(fd, read_buff, BUFFER_SIZE);
       	if (bytes_read > 0)
       	   	res_buff = ft_strjoin(res_buff, read_buff);
	}
	if (bytes_read >= 0)
		return (res_buff);
	else
		return (NULL);
}

 char *ft_cutstr(char *res_buff, char *buff, int index)
{
	char	*new_buff;
	int	i;
	int	j;

	i = 0;
	new_buff = (char*) ft_calloc(index + 1,sizeof(char));
	res_buff = (char*) ft_calloc(ft_strlen(buff) - index,sizeof(char));
	if (!new_buff || !res_buff)
		return (NULL);
	while (i < index)
	{
		res_buff[i] = buff[i];
		i++;
	}
	res_buff[i] = '\0';
	j = 0;
	i++;
	while (i < ft_strlen(buff))
	{
		new_buff[j] = buff[i];
		i++;
		j++;
	}
	new_buff[j] = '\0';
	free(buff);
	return new_buff;	
}

char *get_next_line(int fd)
{
	static char *storage_buff;
	char	*output;
	
	if (fd < 0)
		return (NULL);
	storage_buff = ft_read_fd(fd);	
	if (!storage_buff)
		return (NULL);
	storage_buff = ft_cutstr(output, storage_buff);
	
}
