/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:41:44 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 12:07:27 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_key_mapping(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close_window(keycode, vars);
	else if (keycode == 13)
		ft_move_up(vars);
	else if (keycode == 1)
		ft_move_down(vars);
	else if (keycode == 0)
		ft_move_left(vars);
	else if (keycode == 2)
		ft_move_right(vars);
	return (0);
}
