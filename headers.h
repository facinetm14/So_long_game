/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:10:36 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/01 00:10:36 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "./libs/gnl/get_next_line.h"
# include "./libs/ft_printf/ft_printf.h"
# include "./mlx/mlx.h"

typedef struct s_map
{
	int		fd;
	char	*line;
	char	**data;
	int		*dimension;
	int		exit_x;
	int		exit_y;
}				t_map;
typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	collects;
	int	steps;
}				t_player;
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*sub_img;
	int			img_w;
	int			img_h;
	t_map		*map;
	t_player	*player;
}				t_vars;
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		ft_checker_map_content(char *map_path);
int		*ft_checker_map_dimension(char	*map_path);
t_map	*ft_check_border_l_r(char	*map_path);
t_map	*ft_get_map(t_map	*game_map);
int		ft_map_line(char *s);
int		ft_is_good_value(char c);
int		ft_is_rectangle(int *dimension);
t_map	*ft_check_map(char *map_path);
void	ft_img_mapping(char **sub_image, char c);
void	ft_display_map(t_map *game_map, t_vars *vars);
void	ft_game_start(t_vars *vars);
int		ft_close_window(t_vars *vars);
int		ft_key_mapping(int keycode, t_vars *vars);
void	ft_get_player_pos(char **map_data, t_player *player);
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_right(t_vars *vars);
int		ft_count_collectable(t_map *game_map);
void	ft_update_map_player_move(t_vars *vars, char *sub_image);
void	ft_collect(t_vars *vars);
void	ft_get_map_exit(t_map *game_map);
void	ft_try_exit(t_vars *vars);
int		ft_are_keys_repeat(t_map *game_map);
#endif