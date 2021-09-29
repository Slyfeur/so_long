/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:50 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 13:16:00 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, void *param)
{
	t_so_long	*global;

	global = (t_so_long *)param;
	//printf("x : %i y : %i tab i = %s tab j = %s\n", global->pl->pos_x, global->pl->pos_y, global->map->tab[global->pl->pos_y / 32], global->map->tab[global->pl->pos_x / 32]);
	if (keycode == 53)
		exit(0);
	else if ((keycode == 125 || keycode == 1) && (global->pl->pos_y < global->height - 32)
		&& global->map->tab[(global->pl->pos_y / 32) + 1][global->pl->pos_x / 32] != '1')
	{
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, global->pl->pos_x, global->pl->pos_y);
		global->pl->pos_y += 32;
		ft_printf("move = %d\n",++global->count->move);
		ft_crea(global);
	}
	else if ((keycode == 124 || keycode == 2) && (global->pl->pos_x < global->width - 32)
		&& global->map->tab[global->pl->pos_y / 32][(global->pl->pos_x / 32) + 1] != '1')
	{
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, global->pl->pos_x, global->pl->pos_y);
		global->pl->pos_x += 32;
		ft_printf("move = %d\n",++global->count->move);
		ft_crea(global);
	}
	else if ((keycode == 126 || keycode == 13) && (global->pl->pos_y > 31)
		&& global->map->tab[(global->pl->pos_y / 32) - 1][global->pl->pos_x / 32] != '1')
	{
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, global->pl->pos_x, global->pl->pos_y);
		global->pl->pos_y -= 32;
		ft_printf("move = %d\n",++global->count->move);
		ft_crea(global);
	}
	else if ((keycode == 123 || keycode == 0) && (global->pl->pos_x > 31)
		&& global->map->tab[global->pl->pos_y / 32][(global->pl->pos_x / 32) - 1] != '1')
	{
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, global->pl->pos_x, global->pl->pos_y);
		global->pl->pos_x -= 32;
		ft_printf("move = %d\n",++global->count->move);
		ft_crea(global);
	}
	
	return (0);
}

int	ft_mousepress(void *param)
{
	(void)param;
	exit(0);
}
