/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:34:09 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 23:43:01 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_free_map_elts(t_map *game_map, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (game_map->data[i])
			free(game_map->data[i]);
		i++;
	}
	free(game_map->data);
	free(game_map->dimension);
	close(game_map->fd);
}
