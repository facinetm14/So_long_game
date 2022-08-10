/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:08:34 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 17:26:10 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers.h"

int	main(int argc, char *argv[])
{
	t_map		*game_map;
	t_vars		vars;
	t_player	player;

	if (argc != 2)
		ft_exit_prog(0, NULL);
	game_map = ft_read_map(argv[1]);
	if (ft_are_keys_repeat(game_map) == 0)
	{
		ft_free_map_elts(game_map, game_map->dimension[1]);
		ft_exit_prog(105, game_map);
	}
	ft_display_map(game_map, &vars);
	vars.player = &player;
	vars.map = game_map;
	ft_game_start(&vars);
	return (0);
}
