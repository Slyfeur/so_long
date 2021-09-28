/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:21:33 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:12:17 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_so_long	*ft_init(t_so_long *global)
{
	global->mlx_ptr = mlx_init();
	global->win_ptr = mlx_new_window(global->mlx_ptr,
			global->width, global->height, "So_long");
	global->image = mlx_new_image(global->mlx_ptr,
			global->width, global->height);
	return (global);
}

static t_pixel	*ft_init_pixel(t_pixel *pixel)
{
	pixel->n = 33;
	pixel->m = 33;
	return (pixel);
}

int	main(int argc, char **argv)
{
	t_so_long	*global;
	t_pixel		*pixel;
	t_map		*map;

	if (argc == 2)
	{
		global = malloc(sizeof(t_so_long));
		if (!global)
			return (1);
		pixel = malloc(sizeof(t_pixel));
		if (!pixel)
			return (1);
		map = malloc(sizeof(t_map));
		if (!map)
			return (1);
		global->map = map;
		parse(argv[1], global);
		global = ft_init(global);
		pixel = ft_init_pixel(pixel);
		global->pixel = pixel;
		mlx_hook(global->win_ptr, 2, 1L << 0, &ft_keypress, global);
		mlx_hook(global->win_ptr, 17, 1L << 17, &ft_mousepress, global);
		global->addr = mlx_get_data_addr(global->image, &global->bit_p_p,
				&global->l_l, &global->endian);
		ft_crea_pix(global, pixel);
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr,
			global->image, 0, 0);
		mlx_loop(global->mlx_ptr);
		if (global)
			free(global);
		if (pixel)
			free(pixel);
		if (map)
			free(map);
	}
}
