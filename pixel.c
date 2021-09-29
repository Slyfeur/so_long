/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:34:24 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 12:04:05 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_so_long *global, int x, int y, int color)
{
	char	*dst;

	dst = global->addr + (y * global->l_l + x * (global->bit_p_p / 8));
	*(unsigned int *)dst = color;
}

void	ft_crea_pix(t_so_long *global)
{
	// int	y;
	// int	x;

	if (global->pl->pos_x >= 0 && global->pl->pos_y >= 0
		&& global->pl->pos_x <= global->width - 32
		&& global->pl->pos_y <= global->height - 32)
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->pl->img, global->pl->pos_x, global->pl->pos_y);
}

void	ft_crea(t_so_long *global)
{
	ft_bzero(global->addr, global->width * global->height
		* (global->bit_p_p / 8));
	ft_crea_pix(global);
}
