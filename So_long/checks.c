/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:24:24 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:20:43 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_elements_number_check(t_data *data)
{
	if (data->p != 1)
	{
		write(2, "Error. The map must contain only 1 player!\n", 44);
		ft_finish(data);
	}
	if (data->e != 1)
	{
		write(2, "Error. The map must contain only 1 exit!\n", 42);
		ft_finish(data);
	}
	if (data->c < 1)
	{
		write(2, "Error. The map must contain at least 1 collectible!\n", 53);
		ft_finish(data);
	}
	if (data->m != 1)
	{
		write(2, "Error. The map must contain 1 enemy!", 37);
		ft_finish(data);
	}
}

void	ft_lines_and_columns(t_data *data)
{
	if (data->lines < 3 || data->lines * SIZE > 1800)
	{
		write(2, "Error. Invalid lines length!\n", 30);
		ft_finish(data);
	}
	if (data->columns < 3 || data->columns * SIZE > 1920)
	{
		write(2, "Error. Invalid columns length!\n", 32);
		ft_finish(data);
	}
	ft_coordinates_and_count(data);
	ft_elements_number_check(data);
}

void	ft_elements_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == '0' || data->map[y][x] == '1'
				|| data->map[y][x] == 'P' || data->map[y][x] == 'C'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'M')
				x++;
			else
			{
				write(1, "Error. Invalid elements in map\n", 32);
				ft_finish(data);
			}
		}
		y++;
	}
	ft_lines_and_columns(data);
}

void	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->columns)
	{
		if (data->map[0][x] != '1' || data->map[data->lines - 1][x] != '1')
			ft_finish(data);
		x++;
	}
	while (y < data->lines)
	{
		if (data->map[y][0] != '1' || data->map[y][data->columns - 1] != '1')
			ft_finish(data);
		y++;
	}
}

void	ft_rectangle_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (data->map[y][x] != '\0')
			x++;
		if (x != data->columns)
		{
			write(1, "Error, map is not rectangler\n", 30);
			ft_finish(data);
		}
		y++;
	}
	ft_check_walls(data);
	ft_elements_check(data);
}
