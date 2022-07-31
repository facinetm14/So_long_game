/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:38:23 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/01 01:44:39 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static int	ft_map_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

static int	is_good_value(char c)
{
	if ((c != '1') && (c != '0') && (c != 'E')
		&& (c != 'P') && (c != 'C'))
		return (0);
	return (1);
}

int	checker_map_content(char	*map)
{
	int		fd_map;
	int		i;
	char	*buff;

	fd_map = open(map, O_RDONLY);
	buff = get_next_line(fd_map);
	i = 0;
	while (buff)
	{
		i = 0;
		while (buff[i] != '\0' && buff[i] != '\n')
		{
			if (is_good_value(buff[i]) == 0)
			{
				free(buff);
				return (0);
			}
			i++;
		}
		free(buff);
		buff = get_next_line(fd_map);
	}
	free(buff);
	close(fd_map);
	return (i);
}

int	*checker_map_dimension(char	*map)
{
	int		fd_map;
	char	*buff;
	int		*dimension;

	dimension = malloc(sizeof(int) * 2);
	fd_map = open(map, O_RDONLY);
	buff = get_next_line(fd_map);
	dimension[0] = ft_map_line(buff);
	dimension[1] = 0;
	while (buff)
	{
		if (dimension[0] != ft_map_line(buff))
		{
			free(dimension);
			return (NULL);
		}
		buff = get_next_line(fd_map);
		dimension[1] += 1;
	}
	free(buff);
	close(fd_map);
	return (dimension);
}

/*
** This function is to make sure the map left and right
border is valide, then return t_map
*/
t_map	*ft_check_border_l_r(char	*map)
{
	t_map	*game_map;
	int		i;

	game_map = malloc(sizeof(t_map) * 1);
	game_map->dimension = checker_map_dimension(map);
	if (game_map->dimension == NULL)
		return (NULL);
	game_map->data = malloc(sizeof(char *) * game_map->dimension[1]);
	game_map->fd = open(map, O_RDONLY);
	game_map->line = get_next_line(game_map->fd);
	i = 0;
	while (game_map->line)
	{
		if ((game_map->line[0] != '1')
			|| game_map->line[game_map->dimension[0] - 1] != '1')
		{
			free(game_map);
			return (NULL);
		}
		game_map->data[i] = game_map->line;
		game_map->line = get_next_line(game_map->fd);
		i++;
	}
	return (game_map);
}

/*
** This function return map data but make sure the map top
and bottom border is valide before returning the data
*/

t_map	*ft_get_map(t_map	*game_map)
{
	int	i;

	i = 0;
	if (!game_map)
		return (NULL);
	while(i < game_map->dimension[0])
	{
		if ((game_map->data[0][i] != '1')
			|| game_map->data[game_map->dimension[1] - 1][i] != '1')
		{
			free(game_map);
			return (NULL);
		}
		i++;
	}
	return (game_map);
}