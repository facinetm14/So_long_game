/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:58:52 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 12:06:46 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_game_start(t_vars *vars)
{
	mlx_hook(vars->win, ON_DESTROY, 0, ft_close_window, vars);
	mlx_key_hook(vars->win, ft_key_mapping, vars);
}
