/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:44:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 15:19:44 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_img(t_so_long *global)
{
	int	x;
	int	y;

	global->pl->s_b = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/s_b.XPM", &x, &y);
	global->pl->s_h = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/s_h.XPM", &x, &y);
	global->pl->s_g = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/s_g.XPM", &x, &y);
	global->pl->s_d = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/s_d.XPM", &x, &y);
	global->map->sol = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/sol.XPM", &x, &y);
	global->map->bloc = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/bloc.XPM", &x, &y);
	global->map->col = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/keyblade12.XPM", &x, &y);
	global->map->exit = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/exit1.XPM", &x, &y);
}

static void	wall_img(t_so_long *global)
{
	int	x;
	int	y;

	global->map->m_b = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_b.XPM", &x, &y);
	global->map->m_b_g = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_b_g.XPM", &x, &y);
	global->map->m_b_d = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_b_d.XPM", &x, &y);
	global->map->m_d = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_d.XPM", &x, &y);
	global->map->m_g = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_g.XPM", &x, &y);
	global->map->m_h = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_h.XPM", &x, &y);
	global->map->m_h_g = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_h_g.XPM", &x, &y);
	global->map->m_h_d = mlx_xpm_file_to_image(global->mlx_ptr,
			"xpm/m_h_d.XPM", &x, &y);
}

void	open_img(t_so_long *global)
{
	player_img(global);
	wall_img(global);
}
