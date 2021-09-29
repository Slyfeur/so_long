/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:33:38 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 13:01:21 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg_error)
{
	ft_printf("Error\n%s\n", msg_error);
	exit (-1);
}

void	check_error_map(t_so_long *global)
{
	if (global->count->p != 1)
		ft_error("Wrong number of players");
	else if (global->count->e != 1)
		ft_error("Wrong number of exit");
	//printf("collectible = %d\n", global->count->c);
	else if (global->count->c < 1)
		ft_error("Wrong number of collectible");
}