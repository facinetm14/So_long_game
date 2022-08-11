/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:38:23 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/11 02:11:56 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

int	ft_checker_map_content(char	*map_path)
{
	int		fd_map;
	int		i;
	char	*buff;

	fd_map = open(map_path, O_RDONLY);
	buff = get_next_line(fd_map);
	if (!buff)
		ft_exit_prog(106, NULL);
	i = 0;
	while (buff)
	{
		i = 0;
		while (buff[i] != '\0' && buff[i] != '\n')
		{
			if (ft_is_good_value(buff[i]) == 0)
				ft_exit_prog(100, buff);
			i++;
		}
		free(buff);
		buff = get_next_line(fd_map);
	}
	free(buff);
	close(fd_map);
	return (i);
}

int	*ft_checker_map_dimension(char *map_path)
{
	int		fd_map;
	char	*buff;
	int		*dimension;

	dimension = malloc(sizeof(int) * 2);
	fd_map = open(map_path, O_RDONLY);
	buff = get_next_line(fd_map);
	dimension[0] = ft_map_line(buff);
	dimension[1] = 0;
	while (buff)
	{
		if (dimension[0] != ft_map_line(buff))
		{
			free(dimension);
			ft_exit_prog(101, buff);
		}
		free(buff);
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
t_map	*ft_check_border_l_r(char	*map_path)
{
	t_map	*game_map;
	int		i;

	game_map = malloc(sizeof(t_map) * 1);
	ft_init_map(game_map);
	game_map->dimension = ft_checker_map_dimension(map_path);
	game_map->data = (char **)malloc(sizeof(char *) * game_map->dimension[1]);
	game_map->fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < game_map->dimension[1])
	{
		game_map->data[i] = get_next_line(game_map->fd);
		if ((game_map->data[i][0] != '1')
			|| (game_map->data[i][game_map->dimension[0] - 1] != '1'))
		{
			ft_free_map_elts(game_map, i + 1);
			ft_exit_prog(102, game_map);
		}
		i++;
	}
	close(game_map->fd);
	return (game_map);
}

/*
** This function return map data but make sure the map top
and bottom border is valide before returning the data
*/

t_map	*ft_get_map(t_map	*game_map)
{
	int	i;

	if (ft_is_rectangle(game_map->dimension) == 0)
	{
		ft_free_map_elts(game_map, game_map->dimension[1]);
		ft_exit_prog(104, game_map);
	}
	i = 0;
	while (i < game_map->dimension[0])
	{
		if ((game_map->data[0][i] != '1')
			|| (game_map->data[game_map->dimension[1] - 1][i]) != '1')
		{
			ft_free_map_elts(game_map, game_map->dimension[1]);
			ft_exit_prog(103, game_map);
		}
		i++;
	}
	return (game_map);
}
