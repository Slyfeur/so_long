/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:50 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:08:15 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, void *param)
{
	t_so_long	*global;

	global = (t_so_long *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 125 || keycode == 1)
	{
		if (global->pixel->m < global->height - 32)
			global->pixel->m += 32;
		ft_crea(global, global->pixel);
	}
	else if (keycode == 124 || keycode == 2)
	{
		if (global->pixel->n < global->width - 32)
			global->pixel->n += 32;
		ft_crea(global, global->pixel);
	}
	else if (keycode == 126 || keycode == 13)
	{
		if (global->pixel->m > 32)
			global->pixel->m -= 32;
		ft_crea(global, global->pixel);
	}
	else if (keycode == 123 || keycode == 0)
	{
		if (global->pixel->n > 32)
			global->pixel->n -= 32;
		ft_crea(global, global->pixel);
	}
	return (0);
}

int	ft_mousepress(void *param)
{
	(void)param;
	exit(0);
}
