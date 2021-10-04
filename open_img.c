/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:44:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 14:23:35 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	p_and_m_img(t_so_long *glo)
{
	int	x;
	int	y;

	glo->pl->s_b = mlx_xpm_file_to_image(glo->mlx, "xpm/s_b.XPM", &x, &y);
	glo->pl->s_h = mlx_xpm_file_to_image(glo->mlx, "xpm/s_h.XPM", &x, &y);
	glo->pl->s_g = mlx_xpm_file_to_image(glo->mlx, "xpm/s_g.XPM", &x, &y);
	glo->pl->s_d = mlx_xpm_file_to_image(glo->mlx, "xpm/s_d.XPM", &x, &y);
	glo->map->sol = mlx_xpm_file_to_image(glo->mlx, "xpm/sol.XPM", &x, &y);
	glo->map->bloc = mlx_xpm_file_to_image(glo->mlx, "xpm/bloc.XPM", &x, &y);
	glo->map->exit = mlx_xpm_file_to_image(glo->mlx, "xpm/exit1.XPM", &x, &y);
	glo->map->m_b = mlx_xpm_file_to_image(glo->mlx, "xpm/m_b.XPM", &x, &y);
	glo->map->m_b_g = mlx_xpm_file_to_image(glo->mlx, "xpm/m_b_g.XPM", &x, &y);
	glo->map->m_b_d = mlx_xpm_file_to_image(glo->mlx, "xpm/m_b_d.XPM", &x, &y);
	glo->map->m_d = mlx_xpm_file_to_image(glo->mlx, "xpm/m_d.XPM", &x, &y);
	glo->map->m_g = mlx_xpm_file_to_image(glo->mlx, "xpm/m_g.XPM", &x, &y);
	glo->map->m_h = mlx_xpm_file_to_image(glo->mlx, "xpm/m_h.XPM", &x, &y);
	glo->map->m_h_g = mlx_xpm_file_to_image(glo->mlx, "xpm/m_h_g.XPM", &x, &y);
	glo->map->m_h_d = mlx_xpm_file_to_image(glo->mlx, "xpm/m_h_d.XPM", &x, &y);
	glo->o->o_b = mlx_xpm_file_to_image(glo->mlx, "xpm/e_b.XPM", &x, &y);
	glo->o->o_h = mlx_xpm_file_to_image(glo->mlx, "xpm/e_h.XPM", &x, &y);
	glo->o->o_g = mlx_xpm_file_to_image(glo->mlx, "xpm/e_g.XPM", &x, &y);
	glo->o->o_d = mlx_xpm_file_to_image(glo->mlx, "xpm/e_d.XPM", &x, &y);
}

static void	c_img(t_so_long *glo)
{
	int	x;
	int	y;

	glo->c->k0 = mlx_xpm_file_to_image(glo->mlx, "xpm/k0.XPM", &x, &y);
	glo->c->k1 = mlx_xpm_file_to_image(glo->mlx, "xpm/k1.XPM", &x, &y);
	glo->c->k2 = mlx_xpm_file_to_image(glo->mlx, "xpm/k2.XPM", &x, &y);
	glo->c->k3 = mlx_xpm_file_to_image(glo->mlx, "xpm/k3.XPM", &x, &y);
	glo->c->k4 = mlx_xpm_file_to_image(glo->mlx, "xpm/k4.XPM", &x, &y);
	glo->c->k5 = mlx_xpm_file_to_image(glo->mlx, "xpm/k5.XPM", &x, &y);
	glo->c->k6 = mlx_xpm_file_to_image(glo->mlx, "xpm/k6.XPM", &x, &y);
	glo->c->k7 = mlx_xpm_file_to_image(glo->mlx, "xpm/k7.XPM", &x, &y);
	glo->c->k8 = mlx_xpm_file_to_image(glo->mlx, "xpm/k8.XPM", &x, &y);
	glo->c->k9 = mlx_xpm_file_to_image(glo->mlx, "xpm/k9.XPM", &x, &y);
	glo->c->k10 = mlx_xpm_file_to_image(glo->mlx, "xpm/k10.XPM", &x, &y);
	glo->c->k11 = mlx_xpm_file_to_image(glo->mlx, "xpm/k11.XPM", &x, &y);
	glo->c->k12 = mlx_xpm_file_to_image(glo->mlx, "xpm/k12.XPM", &x, &y);
	glo->c->k13 = mlx_xpm_file_to_image(glo->mlx, "xpm/k13.XPM", &x, &y);
	glo->c->k14 = mlx_xpm_file_to_image(glo->mlx, "xpm/k14.XPM", &x, &y);
	glo->c->k15 = mlx_xpm_file_to_image(glo->mlx, "xpm/k15.XPM", &x, &y);
	glo->c->k16 = mlx_xpm_file_to_image(glo->mlx, "xpm/k16.XPM", &x, &y);
}

void	open_img(t_so_long *glo)
{
	p_and_m_img(glo);
	c_img(glo);
}

void	destroy_p_and_m_img(t_so_long *glo)
{
	mlx_destroy_image(glo->mlx, glo->pl->s_b);
	mlx_destroy_image(glo->mlx, glo->pl->s_h);
	mlx_destroy_image(glo->mlx, glo->pl->s_g);
	mlx_destroy_image(glo->mlx, glo->pl->s_d);
	mlx_destroy_image(glo->mlx, glo->map->sol);
	mlx_destroy_image(glo->mlx, glo->map->bloc);
	mlx_destroy_image(glo->mlx, glo->map->exit);
	mlx_destroy_image(glo->mlx, glo->map->m_b);
	mlx_destroy_image(glo->mlx, glo->map->m_b_g);
	mlx_destroy_image(glo->mlx, glo->map->m_b_d);
	mlx_destroy_image(glo->mlx, glo->map->m_d);
	mlx_destroy_image(glo->mlx, glo->map->m_g);
	mlx_destroy_image(glo->mlx, glo->map->m_h);
	mlx_destroy_image(glo->mlx, glo->map->m_h_g);
	mlx_destroy_image(glo->mlx, glo->map->m_h_d);
	mlx_destroy_image(glo->mlx, glo->o->o_b);
	mlx_destroy_image(glo->mlx, glo->o->o_h);
	mlx_destroy_image(glo->mlx, glo->o->o_g);
	mlx_destroy_image(glo->mlx, glo->o->o_d);
}

void	destroy_c_img(t_so_long *glo)
{
	mlx_destroy_image(glo->mlx, glo->c->k0);
	mlx_destroy_image(glo->mlx, glo->c->k1);
	mlx_destroy_image(glo->mlx, glo->c->k2);
	mlx_destroy_image(glo->mlx, glo->c->k3);
	mlx_destroy_image(glo->mlx, glo->c->k4);
	mlx_destroy_image(glo->mlx, glo->c->k5);
	mlx_destroy_image(glo->mlx, glo->c->k6);
	mlx_destroy_image(glo->mlx, glo->c->k7);
	mlx_destroy_image(glo->mlx, glo->c->k8);
	mlx_destroy_image(glo->mlx, glo->c->k9);
	mlx_destroy_image(glo->mlx, glo->c->k10);
	mlx_destroy_image(glo->mlx, glo->c->k11);
	mlx_destroy_image(glo->mlx, glo->c->k12);
	mlx_destroy_image(glo->mlx, glo->c->k13);
	mlx_destroy_image(glo->mlx, glo->c->k14);
	mlx_destroy_image(glo->mlx, glo->c->k15);
	mlx_destroy_image(glo->mlx, glo->c->k16);
}
