/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:34:24 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/01 11:54:21 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_crea_pix(t_so_long *glo)
{
	if (glo->pl->pos_x >= 0 && glo->pl->pos_y >= 0
		&& glo->pl->pos_x <= glo->width - 32
		&& glo->pl->pos_y <= glo->height - 32 && glo->pl->di == 1)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->pl->s_b, glo->pl->pos_x, glo->pl->pos_y);
	else if (glo->pl->pos_x >= 0 && glo->pl->pos_y >= 0
		&& glo->pl->pos_x <= glo->width - 32
		&& glo->pl->pos_y <= glo->height - 32 && glo->pl->di == 2)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->pl->s_d, glo->pl->pos_x, glo->pl->pos_y);
	else if (glo->pl->pos_x >= 0 && glo->pl->pos_y >= 0
		&& glo->pl->pos_x <= glo->width - 32
		&& glo->pl->pos_y <= glo->height - 32 && glo->pl->di == 3)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->pl->s_h, glo->pl->pos_x, glo->pl->pos_y);
	else if (glo->pl->pos_x >= 0 && glo->pl->pos_y >= 0
		&& glo->pl->pos_x <= glo->width - 32
		&& glo->pl->pos_y <= glo->height - 32 && glo->pl->di == 4)
		mlx_put_image_to_window(glo->mlx, glo->win,
			glo->pl->s_g, glo->pl->pos_x, glo->pl->pos_y);
}

void	ft_crea(t_so_long *glo)
{
	ft_bzero(glo->addr, glo->width * glo->height
		* (glo->bit_p_p / 8));
	ft_crea_pix(glo);
}
