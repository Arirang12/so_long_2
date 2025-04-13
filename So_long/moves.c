/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:51:28 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:34:51 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *data, char c)
{
	ft_putnbr(data->moves + 1);
	if (c == 'M')
		write(1, "\nGAME OVER.👾\n", 17);
	if (c == 'E')
		write(1, "\nWIN.🎉\n", 11);
	ft_finish(data);
}

void	ft_player(t_data *data, int x, int y, char c)
{
	if (c == 'W')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, x * SIZE, y * SIZE);
	else if (c == 'S')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, x * SIZE, y * SIZE);
	else if (c == 'A')
		mlx_put_image_to_window(data->mlx, data->win,
			data->lplayer, x * SIZE, y * SIZE);
	else if (c == 'D')
		mlx_put_image_to_window(data->mlx, data->win,
			data->rplayer, x * SIZE, y * SIZE);
}

void	ft_string_put(t_data *data)
{
	char	*str_moves;

	str_moves = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx, data->win, data->wall,
		1 * SIZE, 0 * SIZE);
	mlx_string_put(data->mlx, data->win, 100, 50, 0xFFFFFF, str_moves);
	free(str_moves);
}

void	ft_move(t_data *data, int x, int y, char c)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->space,
			data->x_p * SIZE, data->y_p * SIZE);
		ft_player(data, x, y, c);
		if (data->map[y][x] == 'C')
			data->c = data->c - 1;
		data->map[data->y_p][data->x_p] = '0';
		data->x_p = x;
		data->y_p = y;
		data->moves++;
		ft_string_put(data);
		ft_putnbr(data->moves);
		ft_putchar('\n');
	}
	if (data->c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			data->x_e * SIZE, data->y_e * SIZE);
	if (data->map[y][x] == 'M')
		game_over(data, 'M');
	if (data->map[y][x] == 'E' && data->c == 0)
		game_over(data, 'E');
}

int	ft_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		write(1, "EXIT\n", 5);
		ft_finish(data);
	}
	if (keycode == W || keycode == 65362)
		ft_move(data, data->x_p, data->y_p - 1, 'W');
	if (keycode == S || keycode == 65364)
		ft_move(data, data->x_p, data->y_p + 1, 'S');
	if (keycode == A || keycode == 65361)
		ft_move(data, data->x_p - 1, data->y_p, 'A');
	if (keycode == D || keycode == 65363)
		ft_move(data, data->x_p + 1, data->y_p, 'D');
	return (0);
}
