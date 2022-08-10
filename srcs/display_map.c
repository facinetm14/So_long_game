/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:53:37 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/11 00:16:36 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

t_map	*ft_read_map(char *map_path)
{
	t_map	*game_map;

	if (ft_checker_map_content(map_path) == 0)
		ft_exit_prog(100, NULL);
	game_map = ft_check_border_l_r(map_path);
	game_map = ft_get_map(game_map);
	return (game_map);
}

void	ft_img_mapping(char **sub_image, char c)
{	
	if (c == '1')
		*sub_image = "./images/wall.xpm";
	else if (c == '0')
		*sub_image = "./images/space.xpm";
	else if (c == 'P')
		*sub_image = "./images/player.xpm";
	else if (c == 'C')
		*sub_image = "./images/collect.xpm";
	else if (c == 'E')
		*sub_image = "./images/exit.xpm";
}

void	ft_display_map(t_map *game_map, t_vars	*vars)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, game_map->dimension[0] * 64,
			game_map->dimension[1] * 64 + 32, "So_long");
	while (y / 64 < game_map->dimension[1])
	{
		i = 0;
		x = 0;
		while (i < game_map->dimension[0])
		{
			ft_img_mapping(&(vars->sub_img), game_map->data[y / 64][i]);
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->sub_img,
					&(vars->img_w), &(vars->img_h));
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			i++;
			x += 64;
		}
		y += 64;
	}
}
