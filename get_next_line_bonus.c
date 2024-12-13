/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/13 16:33:07 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static char	*storage_buff[1024];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strichr(storage_buff[fd], '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(storage_buff[fd], buffer);
		free(storage_buff[fd]);
		storage_buff[fd] = temp;
	}
	if (ft_strichr(storage_buff[fd], '\n') >= 0)
		return (cut_line(&storage_buff[fd], ft_strichr(storage_buff[fd], '\n')));
	else
		return (NULL);
	char *line = storage_buff[fd];
	storage_buff[fd] = NULL;
	return (line);
}
