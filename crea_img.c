/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:44:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 12:14:54 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pl_img(t_so_long *global)
{
	int	x;
	int	y;

	global->pl->img = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/sora_bas.XPM", &x, &y);
	global->map->sol = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/sol.XPM", &x, &y);
	global->map->wall = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/bloc1.XPM", &x, &y);
	global->map->col = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/keyblade1.XPM", &x, &y);
	global->map->exit = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/exit.XPM", &x, &y);
}

void	open_img(t_so_long *global)
{
	pl_img(global);
}