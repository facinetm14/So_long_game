/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:22:20 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/11 00:54:08 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_move_up(t_vars *vars)
{
	if (vars->map->data[(vars->player->pos_y - 64) / 64]
		[vars->player->pos_x / 64] == '1')
		return ;
	if (vars->map->data[(vars->player->pos_y - 64) / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects > 0)
		return ;
	ft_update_map_player_move(vars, "./images/space.xpm");
	vars->player->pos_y -= 64;
	vars->player->steps += 1;
	ft_put_step(vars);
	if (vars->map->data[vars->player->pos_y / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects == 0)
	{
		ft_update_map_player_move(vars, "./images/exit.xpm");
		ft_close_window(vars);
	}
	ft_collect(vars);
	ft_try_exit(vars);
	ft_update_map_player_move(vars, "./images/player.xpm");
}

void	ft_move_down(t_vars *vars)
{
	if (vars->map->data[(vars->player->pos_y + 64) / 64]
		[vars->player->pos_x / 64] == '1')
		return ;
	if (vars->map->data[(vars->player->pos_y + 64) / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects > 0)
		return ;
	ft_update_map_player_move(vars, "./images/space.xpm");
	vars->player->pos_y += 64;
	vars->player->steps += 1;
	ft_put_step(vars);
	if (vars->map->data[vars->player->pos_y / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects == 0)
	{
		ft_update_map_player_move(vars, "./images/exit.xpm");
		ft_close_window(vars);
	}
	ft_collect(vars);
	ft_try_exit(vars);
	ft_update_map_player_move(vars, "./images/player.xpm");
}

void	ft_move_left(t_vars *vars)
{
	if (vars->map->data[vars->player->pos_y / 64]
		[(vars->player->pos_x - 64) / 64] == '1')
		return ;
	if (vars->map->data[vars->player->pos_y / 64]
		[(vars->player->pos_x - 64) / 64] == 'E' && vars->player->collects > 0)
		return ;
	ft_update_map_player_move(vars, "./images/space.xpm");
	vars->player->pos_x -= 64;
	vars->player->steps += 1;
	ft_put_step(vars);
	if (vars->map->data[vars->player->pos_y / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects == 0)
	{
		ft_update_map_player_move(vars, "./images/exit.xpm");
		ft_close_window(vars);
	}
	ft_collect(vars);
	ft_try_exit(vars);
	ft_update_map_player_move(vars, "./images/player.xpm");
}

void	ft_move_right(t_vars *vars)
{
	if (vars->map->data[vars->player->pos_y / 64]
		[(vars->player->pos_x + 64) / 64] == '1')
		return ;
	if (vars->map->data[vars->player->pos_y / 64]
		[(vars->player->pos_x + 64) / 64] == 'E' && vars->player->collects > 0)
		return ;
	ft_update_map_player_move(vars, "./images/space.xpm");
	vars->player->pos_x += 64;
	vars->player->steps += 1;
	ft_put_step(vars);
	if (vars->map->data[vars->player->pos_y / 64]
		[vars->player->pos_x / 64] == 'E' && vars->player->collects == 0)
	{
		ft_update_map_player_move(vars, "./images/exit.xpm");
		ft_close_window(vars);
	}
	ft_collect(vars);
	ft_try_exit(vars);
	ft_update_map_player_move(vars, "./images/player.xpm");
}
