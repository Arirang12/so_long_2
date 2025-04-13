/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:40:54 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 09:16:55 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	int			b;
	char		*buffer;
	char		*line;
	static char	*temp;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = strjoin(line, temp);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b = BUFFER_SIZE;
	while (found_new_line(line, '\n') && b == BUFFER_SIZE)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
			return (free(buffer), free(temp), temp = 0, free(line), NULL);
		if (b == 0 && line == NULL)
			return (free(buffer), free(temp), temp = 0, free(line), NULL);
		buffer[b] = '\0';
		line = strjoin(line, buffer);
	}
	free(temp);
	return (free(buffer), temp = cut_1(line), line = cut_0(line), line);
}
