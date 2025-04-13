/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:24:38 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:21:31 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			ft_finish(data);
		}
		data->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
}

void	ft_image_to_window(t_data *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, data->j
			* SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->j
			* SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->ctbl, data->j
			* SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->j
			* SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->noexit, data->j
			* SIZE, data->i * SIZE);
}

void	ft_fill_window(t_data *data)
{
	while (data->i < data->lines)
	{
		data->j = 0;
		while (data->j < data->columns)
		{
			ft_image_to_window(data);
			data->j++;
		}
		data->i++;
	}
}
