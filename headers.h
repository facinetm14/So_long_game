/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:10:36 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/01 00:10:36 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "libs/get_next_line.h"

typedef struct s_map
{
	int		fd;
	char	*line;
	char	**data;
	int		*dimension;
}				t_map;

int		checker_map_content(char *map);
int		*checker_map_dimension(char	*map);
t_map	*ft_check_border_l_r(char	*map);
t_map	*ft_get_map(t_map	*game_map);

#endif