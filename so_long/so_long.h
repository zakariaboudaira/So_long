/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:16:54 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 07:48:39 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PXL 

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>

typedef struct data
{
	int		n_en;
	int		n1_en;
	int		i1;
	int		j1;
	int		en;
	int		*dir;
	void	*mlx;
	void	*mlx_win;
	int		w;
	int		h;
	int		p;
	int		coinscounter;
	int		movescounter;
	int		counter;
	int		p1;
	int		p2;
	int		column;
	int		line;
	int		pcount;
	int		ecount;
	int		x;
	int		y;
	void	*img;
	char	**map;
	void	*empty;
	void	*door;
	void	*player1;
	void	*player2;
	int		i;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*enemy1;
	void	*enemy2;
	void	*bar;
	void	*lose;
	char	*saved;
}t_data;

char	**ft_split(char	const *s, char c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		set_up_map(char *path, t_data *map);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	const *s, unsigned	int start, size_t len);
size_t	ft_strlen(const char	*str);
void	set_line(char *str, t_data *map);
void	set_column(char *str, t_data *map);
char	check_map(t_data *map);
char	*set_window(t_data *data);
void	so_long(t_data *data);
char	move_player(t_data *data, int s);
char	move_right(t_data *data);
char	move_left(t_data *data);
char	move_up(t_data *data);
char	move_down(t_data *data);
char	move_right(t_data *data);
void	ft_exit(void);
void	move_enemy(t_data *data);
char	*ft_itoa(int n);
char	wall_checker(t_data *data);
char	wall_checker2(t_data *data);
char	checker(t_data *data);
void	put_player3(t_data *data);
void	put_player2(t_data *data);
void	put_player1(t_data *data);
void	put_player(t_data *data);
void	counter(t_data *data);
void	gui(t_data *data);
void	set_coins(t_data *data, void *img);
int		anime(t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);
void	p2(t_data	*data);
void	p3(t_data	*data);
void	p1(t_data	*data);
void	p(t_data	*data);
void	put_bar(t_data *data);
void	put1(t_data	*data, int j, int i);
void	put2(t_data *data, int j, int i, char *ret);
void	move(t_data *data);
void	move2(t_data *data);
int		set_map(char *path, t_data *data);
void	put_window(t_data *data, int i, int j);
void	ui(t_data *data);
char	lines_checker(t_data *data);
int		newline_checker(t_data *data);
void	dir(t_data *data);
void	ini(t_data *data);
int		ft_strcmp(char	*s1, char	*s2);
void	check_extention(char *path);

#endif
