/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:34:24 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 11:48:22 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_crea_pix(t_so_long *global)
{
	if (global->pl->pos_x >= 0 && global->pl->pos_y >= 0
		&& global->pl->pos_x <= global->width - 32
		&& global->pl->pos_y <= global->height - 32)
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->pl->s_b, global->pl->pos_x, global->pl->pos_y);
}

void	ft_crea(t_so_long *global)
{
	ft_bzero(global->addr, global->width * global->height
		* (global->bit_p_p / 8));
	ft_crea_pix(global);
}
