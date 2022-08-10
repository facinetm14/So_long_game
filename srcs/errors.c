/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:48:19 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 23:37:24 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_error_message(int code)
{
	if (code == 0)
		ft_printf("Error\nShould have one map");
	if (code == 100)
		ft_printf("Error\nBad content in map");
	if (code == 101)
		ft_printf("Error\nMisconfig map's number of columns");
	if (code == 102 || code == 103)
		ft_printf("Error\nThe map should be surrounded by walls");
	if (code == 104)
		ft_printf("Error\nThe map should be rectangle");
	if (code == 105)
		ft_printf("Error\nThe map must have 1 P, at least 1 E and at least 1 C");
	if (code == 106)
		ft_printf("Error\nEmpty map");
}
