/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:32:10 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 22:56:15 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_map_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_is_good_value(char c)
{
	if ((c != '1') && (c != '0') && (c != 'E')
		&& (c != 'P') && (c != 'C'))
		return (0);
	return (1);
}

int	ft_is_rectangle(int *dimension)
{
	if (dimension[0] == dimension[1])
		return (0);
	return (1);
}

int	ft_count_collectable(t_map *game_map)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	nb = 0;
	while (j < game_map->dimension[1])
	{
		i = 0;
		while (i < game_map->dimension[0])
		{
			if (game_map->data[j][i] == 'C')
				nb++;
			i++;
		}
		j++;
	}
	return (nb);
}
