/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:38:23 by fakouyat          #+#    #+#             */
/*   Updated: 2022/07/30 19:30:11 by fakouyat         ###   ########.fr       */
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

int	checker_map_content(char	*map)
{
	int		fd_map;
	int		i;
	char	*read_map;

	fd_map = open(map, O_RDONLY);
	read_map = get_next_line(fd_map);
	i = 0;
	while (read_map)
	{
		i = 0;
		while (read_map[i] != '\0' && read_map[i] != '\n')
		{
			if ((read_map[i] != '1') && (read_map[i] != '0')
				&& (read_map[i] != 'E') && (read_map[i] != 'P')
				&& (read_map[i] != 'C'))
			{
				free(read_map);
				return(0);
			}
			i++;
		}
		free(read_map);
		read_map = get_next_line(fd_map);
	}
	free(read_map);
	close(fd_map);
	return (i);
}

int	*checker_map_dimension(char	*map)
{
	int		fd_map;
	char	*read_map;
	int		*dimension;

	dimension = malloc(sizeof(int) * 2);
	fd_map = open(map, O_RDONLY);
	read_map = get_next_line(fd_map);
	dimension[0] = ft_map_line(read_map);
	dimension[1] = 0;
	while (read_map)
	{
		if (dimension[0] != ft_map_line(read_map))
		{
			free(dimension);
			return (NULL);
		}
		read_map = get_next_line(fd_map);
		dimension[1] += 1;
	}
	free(read_map);
	close(fd_map);
	return (dimension);
}

char **ft_get_map(char	*map)
{
	int		fd_map;
	char	*read_map;
	char	**data_map;
	char	*dimension;
	int		i;

	dimension = checker_map_dimension(map)
	if (dimension == NULL)
		return (NULL);
	data_map = malloc(sizeof(char *) * dimension[1]);
	fd_map = open(map, O_RDONLY);
	read_map = get_next_line(fd_map);
	i = 0;
	while (read_map)
	{
		if(read_map[0] != '1' && read_map[dimension[0] - 1] != '1')
		{
			free(data_map);
			free(dimension);
			return (NULL);
		}
		data_map[i] = read_map;
		read_map = read_map = get_next_line(fd_map);
		i++;
	}
	return (data_map);
}
