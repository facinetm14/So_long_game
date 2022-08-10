/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:58:52 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/11 01:09:27 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_try_exit(t_vars *vars)
{
	char	*sub_image;

	sub_image = "./images/exit_opened.xpm";
	if (vars->player->collects == 0)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, sub_image, &(vars->img_w),
				&(vars->img_h));
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->map->exit_x, vars->map->exit_y);
	}
}

void	ft_game_start(t_vars *vars)
{
	ft_get_map_exit(vars->map);
	ft_get_player_pos(vars->map->data, vars->player);
	mlx_string_put(vars->mlx, vars->win, vars->map->dimension[0] * 64 / 2 - 64,
		vars->map->dimension[1] * 64 + 16, 0x00FFFFFF, "steps : ");
	vars->player->collects = ft_count_collectable(vars->map);
	vars->player->steps = 0;
	mlx_hook(vars->win, ON_DESTROY, 0, ft_close_window, vars);
	mlx_key_hook(vars->win, ft_key_mapping, vars);
	mlx_loop(vars->mlx);
}
