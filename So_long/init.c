/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:26:01 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 09:50:12 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(t_data *data)
{
	int		count;
	char	*str;

	count = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (str == NULL)
			break ;
		count++;
		free(str);
	}
	free(str);
	return (count);
}

void	ft_init2(t_data *data)
{
	data->map = 0;
	data->map2 = 0;
	data->fd = 0;
	data->columns = 0;
	data->i = 0;
	data->j = 0;
	data->x_p = 0;
	data->y_p = 0;
	data->x_m = 0;
	data->y_m = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->m = 0;
	data->moves = 0;
	data->x = 0;
	data->y = 0;
}

void	ft_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->player = 0;
	data->rplayer = 0;
	data->lplayer = 0;
	data->wall = 0;
	data->space = 0;
	data->ctbl = 0;
	data->exit = 0;
	data->noexit = 0;
	data->enemy = 0;
	data->enemy_plus = 0;
	data->lines = 0;
	data->x_e = 0;
	data->y_e = 0;
	ft_init2(data);
}
