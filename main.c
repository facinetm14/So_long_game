/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:08:34 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/08 12:11:28 by fakouyat         ###   ########.fr       */
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
	ft_display_map(game_map, &vars);
	ft_get_player_pos(game_map->data, &player);
	player.collects = ft_count_collectable(game_map);
	vars.player = &player;
	vars.map = game_map;
	ft_game_start(&vars);
	mlx_loop(vars.mlx);
	free(game_map);
	return (0);
}
