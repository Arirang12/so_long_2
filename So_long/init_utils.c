/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 05:19:49 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:40:21 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_extracoor(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		data->x_e = x;
		data->y_e = y;
		data->e++;
	}
	else if (data->map[y][x] == 'M')
	{
		data->x_m = x;
		data->y_m = y;
		data->m++;
	}
}

void	ft_coordinates_and_count(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == 'P')
			{
				data->x_p = x;
				data->y_p = y;
				data->p++;
			}
			if (data->map[y][x] == 'C')
				data->c++;
			if (data->map[y][x] == 'E')
				ft_extracoor(data, x, y);
			if (data->map[y][x] == 'M')
				ft_extracoor(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
