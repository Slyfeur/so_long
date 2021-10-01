/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:26:44 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/01 13:24:07 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_bas(t_so_long *glo)
{
	ft_printf("move = %d\n", ++glo->count->move);
	pr_move(glo);
	if (glo->map->tab[(glo->pl->pos_y / 32)]
		[glo->pl->pos_x / 32] == 'E' && glo->count->c > 0)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->exit, glo->pl->pos_x, glo->pl->pos_y);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] != 'E')
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->pl->pos_x, glo->pl->pos_y);
	glo->pl->pos_y += 32;
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'C')
	{
		glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] = '0';
		glo->count->c--;
	}
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c <= 0)
		pr_mess(glo, 0);
	glo->pl->di = 1;
	ft_crea(glo);
}

void	m_droite(t_so_long *glo)
{
	ft_printf("move = %d\n", ++glo->count->move);
	pr_move(glo);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c > 0)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->exit,
			glo->pl->pos_x, glo->pl->pos_y);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] != 'E')
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->pl->pos_x, glo->pl->pos_y);
	glo->pl->pos_x += 32;
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'C')
	{
		glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] = '0';
		glo->count->c--;
	}
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c <= 0)
		pr_mess(glo, 0);
	glo->pl->di = 2;
	ft_crea(glo);
}

void	m_haut(t_so_long *glo)
{
	ft_printf("move = %d\n", ++glo->count->move);
	pr_move(glo);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c > 0)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->exit,
			glo->pl->pos_x, glo->pl->pos_y);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] != 'E')
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->pl->pos_x, glo->pl->pos_y);
	glo->pl->pos_y -= 32;
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'C')
	{
		glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] = '0';
		glo->count->c--;
	}
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c <= 0)
		pr_mess(glo, 0);
	glo->pl->di = 3;
	ft_crea(glo);
}

void	m_gauche(t_so_long *glo)
{
	ft_printf("move = %d\n", ++glo->count->move);
	pr_move(glo);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c > 0)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->exit,
			glo->pl->pos_x, glo->pl->pos_y);
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] != 'E')
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
			glo->pl->pos_x, glo->pl->pos_y);
	glo->pl->pos_x -= 32;
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'C')
	{
		glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] = '0';
		glo->count->c--;
	}
	if (glo->map->tab[(glo->pl->pos_y / 32)][glo->pl->pos_x / 32] == 'E'
		&& glo->count->c <= 0)
		pr_mess(glo, 0);
	glo->pl->di = 4;
	ft_crea(glo);
}
