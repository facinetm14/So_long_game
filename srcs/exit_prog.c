/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:26:19 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/10 15:52:52 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

void	ft_exit_prog(int code, void *vars)
{
	ft_error_message(code);
	if (vars)
		free(vars);
	exit(0);
}
