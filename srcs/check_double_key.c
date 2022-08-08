/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:48:29 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 22:11:55 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_are_keys_repeat(t_map *game_map)
{
	int	keys[2];
	int	i;
	int	j;

	keys[0] = 0;
	keys[1] = 0;
	j = 0;
	while (j < game_map->dimension[1])
	{
		i = 0;
		while (i < game_map->dimension[0])
		{
			if (game_map->data[j][i] == 'P')
				keys[0] += 1;
			if (game_map->data[j][i] == 'E')
				keys[1] += 1;
			if (keys[0] > 1 || keys[1] > 1)
				return (0);
			i++;
		}
		j++;
	}
	if (keys[0] == 1 && keys[1] == 1)
		return (1);
	return (0);
}
