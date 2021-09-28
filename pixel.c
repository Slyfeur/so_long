/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:34:24 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:07:46 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_so_long *global, int x, int y, int color)
{
	char	*dst;

	dst = global->addr + (y * global->l_l + x * (global->bit_p_p / 8));
	*(unsigned int *)dst = color;
}

void	ft_crea_pix(t_so_long *global, t_pixel *pixel)
{
	int	y;
	int	x;

	if (pixel->n >= 0 && pixel->m >= 0 && pixel->n <= global->width - 32
		&& pixel->m <= global->height - 32)
	{
		y = 0;
		while (y < 32)
		{
			x = 0;
			while (x < 32)
			{
				my_mlx_pixel_put(global, pixel->n
					+ x, pixel->m + y, 0x00FF0000);
				x++;
			}
			y++;
		}
	}
}

void	ft_crea(t_so_long *global, t_pixel *pixel)
{
	ft_bzero(global->addr, global->width * global->height
		* (global->bit_p_p / 8));
	ft_crea_pix(global, pixel);
	mlx_put_image_to_window(global->mlx_ptr, global->win_ptr,
		global->image, 0, 0);
}
