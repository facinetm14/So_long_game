/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:08:34 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 22:22:14 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char *argv[])
{
	t_map		*game_map;
	t_vars		vars;
	t_player	player;

	if (argc != 2)
	{
		ft_printf("Error\nShould have one map");
		return (0);
	}
	game_map = ft_check_map(argv[1]);
	if (!game_map)
		return (0);
	if (ft_are_keys_repeat(game_map) == 0)
	{
		free(game_map);
		ft_printf("Error\nThe map should have one player and map exit");
		return (0);
	}
	ft_display_map(game_map, &vars);
	vars.player = &player;
	vars.map = game_map;
	ft_game_start(&vars);
	free(game_map);
	return (0);
}
