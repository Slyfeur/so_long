/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:47:45 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/01 15:48:20 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pr_exit_to_im(t_so_long *glo, int i, int j)
{
	mlx_put_image_to_window(glo->mlx, glo->win, glo->map->exit, j * 32, i * 32);
}

void	pr_ground_to_im(t_so_long *glo, int i, int j)
{
	mlx_put_image_to_window(glo->mlx, glo->win, glo->map->sol, j * 32, i * 32);
}

void	pr_corner_w_to_im(t_so_long *glo, int i, int j)
{
	if (i == 0 && j == 0)
		pr_move(glo);
	else if (i == 0 && j == (glo->w_map - 1))
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_h_d, j * 32, i * 32);
	else if (i == 0 && j < glo->w_map - 1)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_h, j * 32, i * 32);
	else if (i == glo->h_map - 1 && j == 0)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_b_g, j * 32, i * 32);
	else if (i == glo->h_map - 1 && j == glo->w_map - 1)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_b_d, j * 32, i * 32);
}

void	pr_side_w_to_im(t_so_long *glo, int i, int j)
{
	if (i > 0 && i < glo->h_map - 1 && j == 0)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_g, j * 32, i * 32);
	else if (i > 0 && i < glo->h_map - 1 && j
		== glo->w_map - 1)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_d, j * 32, i * 32);
	else if (i == glo->h_map - 1 && j < glo->w_map - 1)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->m_b, j * 32, i * 32);
	else
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->map->bloc, j * 32, i * 32);
}

void	pr_w_to_im(t_so_long *glo, int i, int j)
{
	if ((i == 0 && j == 0 ) || (i == 0 && j == (glo->w_map - 1))
		|| (i == 0 && j < glo->w_map - 1) || (i == glo->h_map - 1 && j == 0)
		|| (i == glo->h_map - 1 && j == glo->w_map - 1))
		pr_corner_w_to_im(glo, i, j);
	else
		pr_side_w_to_im(glo, i, j);
}
