/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:41:52 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 08:42:01 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "so_long.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*strjoin(char *s1, char *s2);
int		found_new_line(char *str, int c);
char	*cut_0(char *line);
char	*cut_1(char *str);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, const char *src);

#endif
