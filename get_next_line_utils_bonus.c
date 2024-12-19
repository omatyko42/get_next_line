/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:13:05 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/17 12:52:53 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;

	if (size != 0 && count > ((size_t)-1) / size)
		return (NULL);
	n = count * size;
	ptr = (char *)malloc(n);
	if (!ptr)
		return (NULL);
	else
	{
		while (n--)
			ptr[n] = 0;
	}
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len1)
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
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (ft_strlen(s));
	else
		return (-1);
	return (-1);
}

char	*cut_line(char **storage, int newline_index)
{
	char	*line;
	char	*new_storage;
	int		i;

	line = ft_calloc(newline_index + 2, 1);
	new_storage = ft_calloc(ft_strlen(*storage) - newline_index, 1);
	if (!line || !new_storage)
		return (free(line), free(new_storage), NULL);
	i = 0;
	while (i <= newline_index)
	{
		line[i] = (*storage)[i];
		i++;
	}
	line[i] = '\0';
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
