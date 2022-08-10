/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:22:16 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 23:43:31 by fakouyat         ###   ########.fr       */
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
