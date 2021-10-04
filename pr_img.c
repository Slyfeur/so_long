/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:50:58 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 08:58:59 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pr_c(t_so_long *glo, int i, int j)
{
	if (glo->c->nbr == 0)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k0, j * 32, i * 32);
	else if (glo->c->nbr == 1)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k1, j * 32, i * 32);
	else if (glo->c->nbr == 2)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k2, j * 32, i * 32);
	else if (glo->c->nbr == 3)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k3, j * 32, i * 32);
	else if (glo->c->nbr == 4)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k4, j * 32, i * 32);
	else if (glo->c->nbr == 5)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k5, j * 32, i * 32);
	else if (glo->c->nbr == 6)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k6, j * 32, i * 32);
	else if (glo->c->nbr == 7)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k7, j * 32, i * 32);
}

void	pr_c1(t_so_long *glo, int i, int j)
{
	if (glo->c->nbr == 8)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k8, j * 32, i * 32);
	else if (glo->c->nbr == 9)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->c->k9, j * 32, i * 32);
	else if (glo->c->nbr == 10)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k10, j * 32, i * 32);
	else if (glo->c->nbr == 11)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k11, j * 32, i * 32);
	else if (glo->c->nbr == 12)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k12, j * 32, i * 32);
	else if (glo->c->nbr == 13)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k13, j * 32, i * 32);
	else if (glo->c->nbr == 14)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k14, j * 32, i * 32);
	else if (glo->c->nbr == 15)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k15, j * 32, i * 32);
	else if (glo->c->nbr == 16)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->c->k16, j * 32, i * 32);
}

void	pr_p_to_im(t_so_long *glo)
{
	mlx_put_image_to_window(glo->mlx, glo->win,
		glo->map->sol, glo->pl->pos_x, glo->pl->pos_y);
	mlx_put_image_to_window(glo->mlx, glo->win,
		glo->pl->s_b, glo->pl->pos_x, glo->pl->pos_y);
}

void	pr_c_to_im(t_so_long *glo, int i, int j)
{
	mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol,
		j * 32, i * 32);
	if (glo->c->nbr < 8)
		pr_c(glo, i, j);
	else
		pr_c1(glo, i, j);
	glo->c->nbr++;
}

void	pr_img_to_wind(t_so_long *glo)
{
	int	j;

	glo->count->img_to_wind = 0;
	glo->c->nbr = 0;
	while (glo->count->img_to_wind < glo->h_map)
	{
		j = 0;
		while (j < glo->w_map)
		{
			if (glo->map->tab[glo->count->img_to_wind][j] == 'P')
				pr_p_to_im(glo);
			else if (glo->map->tab[glo->count->img_to_wind][j] == '0')
				pr_ground_to_im(glo, glo->count->img_to_wind, j);
			else if (glo->map->tab[glo->count->img_to_wind][j] == '1')
				pr_w_to_im(glo, glo->count->img_to_wind, j);
			else if (glo->map->tab[glo->count->img_to_wind][j] == 'C')
				pr_c_to_im(glo, glo->count->img_to_wind, j);
			else if (glo->map->tab[glo->count->img_to_wind][j] == 'E')
				pr_exit_to_im(glo, glo->count->img_to_wind, j);
			j++;
			if (glo->c->nbr == 17)
				glo->c->nbr = 0;
		}
		glo->count->img_to_wind++;
	}
}
