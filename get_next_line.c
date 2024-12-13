/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/13 18:52:49 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *storage_buff = NULL;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (ft_strichr(storage_buff, '\n') == -1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(storage_buff, buffer);
        free(storage_buff);
        storage_buff = temp;
        if (!storage_buff)
            return (NULL);
    }
    if (ft_strichr(storage_buff, '\n') >= 0)
        return (cut_line(&storage_buff, ft_strichr(storage_buff, '\n')));
    if (storage_buff && *storage_buff != '\0')
    {
        temp = storage_buff;
        storage_buff = NULL;
        return (temp);
    }
    free(storage_buff);
    storage_buff = NULL;
    return (NULL);
}




