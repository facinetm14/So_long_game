/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:31:34 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 22:56:21 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_get_player_pos(char **map_data, t_player *player)
{
	int			i;
	int			j;

	j = 0;
	while (map_data[j])
	{
		i = 0;
		while (map_data[j][i] != '\0')
		{
			if (map_data[j][i] == 'P')
			{
				player->pos_x = i * 64;
				player->pos_y = j * 64;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	ft_update_map_player_move(t_vars *vars, char *sub_image)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, sub_image,
			&(vars->img_w), &(vars->img_h));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->player->pos_x, vars->player->pos_y);
}

void	ft_collect(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->pos_x / 64;
	y = vars->player->pos_y / 64;
	if (vars->map->data[y][x] == 'C')
	{
		vars->player->collects -= 1;
		vars->map->data[y][x] = '0';
	}
}

void	ft_get_map_exit(t_map *game_map)
{
	int			i;
	int			j;

	j = 0;
	while (game_map->data[j])
	{
		i = 0;
		while (game_map->data[j][i] != '\0')
		{
			if (game_map->data[j][i] == 'E')
			{
				game_map->exit_x = i * 64;
				game_map->exit_y = j * 64;
				return ;
			}
			i++;
		}
		j++;
	}
}