/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:12:27 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/11 16:50:23 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE+1];
	int bytes_read;
	
	bytes_read = 0;
	bytes_read = read(fd,buffer, BUFFER_SIZE);	
	if (bytes_read < 0)
		return (NULL);

	return buffer;
}
