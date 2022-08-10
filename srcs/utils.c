/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:22:16 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/11 01:15:41 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_init_map(t_map	*map_game)
{
	map_game->fd = 0;
	map_game->data = NULL;
	map_game->exit_x = 0;
	map_game->exit_y = 0;
}

void	ft_put_step(t_vars *vars)
{
	char	*str;
	char	*previous;

	str = ft_itoa(vars->player->steps);
	previous = ft_itoa(vars->player->steps - 1);
	mlx_string_put(vars->mlx, vars->win, vars->map->dimension[0] * 64 / 2,
		vars->map->dimension[1] * 64 + 16, 0x00000000, previous);
	mlx_string_put(vars->mlx, vars->win, vars->map->dimension[0] * 64 / 2,
		vars->map->dimension[1] * 64 + 16, 0x00FFFFFF,
		str);
	free(str);
	free(previous);
}
