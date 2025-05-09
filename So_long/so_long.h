/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 05:04:27 by zhassna           #+#    #+#             */
/*   Updated: 2025/04/13 11:13:17 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SIZE 60
# define WALL "blocks/WALL.xpm"
# define SPACE "blocks/SPACE.xpm"
# define CTBL "blocks/drgnball.xpm"
# define PLAYER "blocks/PLAYER.xpm"
# define RPLAYER "blocks/RPLAYER.xpm"
# define LPLAYER "blocks/LPLAYER.xpm"
# define EXIT "blocks/EXITOPEN.xpm"
# define NOEXIT "blocks/EXITCLOSE.xpm"
# define ENEMY "blocks/ENEMY.xpm"
# define ENEMYP "blocks/ENEMY_P.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*rplayer;
	void	*lplayer;
	void	*wall;
	void	*space;
	void	*ctbl;
	void	*exit;
	void	*noexit;
	void	*enemy;
	void	*enemy_plus;
	char	**map;
	char	**map2;
	int		fd;
	int		lines;
	int		columns;
	int		i;
	int		j;
	int		x_p;
	int		y_p;
	int		x_m;
	int		y_m;
	int		x_e;
	int		y_e;
	int		c;
	int		e;
	int		p;
	int		m;
	int		moves;
	int		x;
	int		y;
}			t_data;

# define W 119
# define S 115
# define A 97
# define D 100

int			ft_count_lines(t_data *data);
int			ft_algo(t_data *data, int x, int y);
int			ft_finish(t_data *data);
int			ft_handler(int keycode, t_data *data);
int			ft_strlen(char *str);
void		ft_elements_number_check(t_data *data);
void		ft_lines_and_columns(t_data *data);
void		ft_elements_check(t_data *data);
void		ft_rectangle_check(t_data *data);
void		ft_check_walls(t_data *data);
void		ft_create_map(t_data *data);
void		ft_fill_window(t_data *data);
void		ft_map_dup(t_data *data);
void		ft_flood_fill(t_data *data);
void		ft_free_map(t_data *data);
void		ft_free_map2(t_data *data);
int			ft_map(t_data *data, char *file);
void		ft_img(t_data *data);
void		ft_check_file(t_data *data, char *file);
void		ft_move(t_data *data, int x, int y, char c);
void		ft_coordinates_and_count(t_data *data);
void		ft_init(t_data *data);
int			ft_animation(t_data *data);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *src);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_itoa(int n);
void		ft_counter(t_data *data);

char		*get_next_line(int fd);
char		*ft_next_update(char *str);
char		*ft_extract_line(char *str);
char		*ft_reads(int fd, char *str);
char		*ft_strjoin(char *str, char *buf);
char		*free_buf(char *buf);
char		*ft_search_nl(char *str, char c);
void		ft_img_error(t_data *data);
int			close_window(void *param);
int			ft_enemy_sprite_animation(t_data *data);

#endif
