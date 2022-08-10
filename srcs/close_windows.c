/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:03:47 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 17:27:16 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_map_elts(vars->map, vars->map->dimension[1]);
	free(vars->map);
	exit(0);
	return (0);
}
