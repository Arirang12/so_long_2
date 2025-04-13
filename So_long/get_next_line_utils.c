/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 08:42:42 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 08:42:44 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *s1, char *s2)
{
	char	*all_str;
	int		n;
	int		i;
	int		total_len;

	if (!s2 || (!s1 && !s2))
		return (NULL);
	else if (!s1)
		return ((all_str = malloc(ft_strlen(s2) + 1)), ft_strcpy(all_str, s2),
			all_str);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	all_str = (char *)malloc(total_len * sizeof(char) + 1);
	if (!all_str)
		return (NULL);
	while (s1[++i] != '\0')
		all_str[i] = s1[i];
	n = 0;
	while (s2[n])
	{
		all_str[i] = s2[n];
		i++;
		n++;
	}
	return (free((char *)s1), all_str[i] = '\0', all_str);
}

int	found_new_line(char *str, int c)
{
	if (!str)
		return (1);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (0);
	else
		return (1);
}

char	*cut_0(char *line)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (!line)
		return (NULL);
	if (line[0] == '\n')
		return (free(line), temp = malloc(2), temp[0] = '\n', temp[1] = '\0',
			temp);
	while (line[i] && line[i] != '\n')
		i++;
	temp = malloc(i + 2);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		temp[i] = line[i];
		i++;
	}
	if (!line[i])
		return (free(line), temp[i] = '\0', temp);
	if (line[i] == '\n')
		temp[i] = '\n';
	return (temp[i + 1] = '\0', free(line), temp);
}

char	*cut_1(char *str)
{
	int		i;
	int		b;
	char	*temp;

	i = 0;
	b = 0;
	if (found_new_line(str, '\n'))
		return (NULL);
	while (str[i] != '\n')
		i++;
	if (++i && !str[i])
		return (NULL);
	while (str[i])
	{
		b++;
		i++;
	}
	temp = malloc(b + 1);
	if (!temp)
		return (NULL);
	i -= b;
	b = 0;
	while (str[i])
		temp[b++] = str[i++];
	return (temp[b] = '\0', temp);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
