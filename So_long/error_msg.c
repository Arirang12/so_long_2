/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:35:33 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:21:14 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_error(t_data *data)
{
	write(1, "Error. Can't put file to image\n", 31);
	ft_finish(data);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_finish(data);
	return (0);
}

int	ft_enemy_sprite_animation(t_data *data)
{
	static int	i;
	static int	frame_counter;

	frame_counter++;
	if (i <= 30)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy, data->x_m * SIZE, data->y_m * SIZE);
	}
	else if (i <= 60)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy_plus, data->x_m * SIZE, data->y_m * SIZE);
		if (i == 60)
			i = 0;
	}
	if (frame_counter >= 50)
	{
		i++;
		frame_counter = 0;
	}
	return (0);
}
