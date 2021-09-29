/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:44:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 11:13:16 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pl_img(t_so_long *global)
{
	int	x;
	int	y;

	global->image = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/sora_bas.XPM", &x, &y);
	mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->image, global->pl->pos_x, global->pl->pos_y);
}

void	open_img(t_so_long *global)
{
	pl_img(global);
}