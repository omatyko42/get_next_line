/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:14:04 by omatyko           #+#    #+#             */
/*   Updated: 2024/12/13 16:33:51 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#else
#if BUFFER_SIZE > 8000000
#undef BUFFER_SIZE
# define BUFFER_SIZE 8000000
#endif
#endif

char	*get_next_line_bonus(int fd);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strichr(const char *s, int c);
char	*cut_line(char **storage, int newline_index);
#endif