/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:48:51 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 15:49:20 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	opponent_move(t_so_long *glo)
{
	if (glo->pl->di == 1 && glo->map->tab[glo->o->pos_y / 32 - 1]
	[glo->o->pos_x / 32] == '0')
	{
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = '0';
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->o->pos_x, glo->o->pos_y);
		glo->o->pos_y -= 32;
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = 'O';
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->o->o_h, glo->o->pos_x, glo->o->pos_y);
	}
	if (glo->pl->di == 2 && glo->map->tab[glo->o->pos_y / 32]
	[glo->o->pos_x / 32 - 1] == '0')
	{
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = '0';
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->o->pos_x, glo->o->pos_y);
		glo->o->pos_x -= 32;
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = 'O';
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->o->o_g, glo->o->pos_x, glo->o->pos_y);
	}
	if (glo->pl->di == 3 && glo->map->tab[glo->o->pos_y / 32 + 1]
	[glo->o->pos_x / 32] == '0')
	{
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = '0';
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->o->pos_x, glo->o->pos_y);
		glo->o->pos_y += 32;
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = 'O';
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->o->o_b, glo->o->pos_x, glo->o->pos_y);
	}
	if (glo->pl->di == 4 && glo->map->tab[glo->o->pos_y / 32]
	[glo->o->pos_x / 32 + 1] == '0')
	{
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = '0';
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->o->pos_x, glo->o->pos_y);
		glo->o->pos_x += 32;
		glo->map->tab[glo->o->pos_y / 32][glo->o->pos_x / 32] = 'O';
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->o->o_d, glo->o->pos_x, glo->o->pos_y);
	}
}