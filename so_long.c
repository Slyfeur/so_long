/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:21:33 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 11:17:39 by tuytters         ###   ########.fr       */
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

static t_so_long	*ft_malloc_all(t_so_long *global)
{
	t_pixel		*pixel;
	t_map		*map;
	t_pl	*pl;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		ft_error("Error\nMalloc failed\n");
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Error\nMalloc failed\n");
	pl = malloc(sizeof(t_pl));
	if (!pl)
		ft_error("Error\nMalloc failed\n");
	global->pl = pl;
	global->map = map;
	global->pixel = pixel;
	return (global);
}

int	main(int argc, char **argv)
{
	t_so_long	*global;

	if (argc == 2)
	{
		global = malloc(sizeof(t_so_long));
		if (!global)
			ft_error("Error\nMalloc failed\n");
		ft_malloc_all(global);
		parse(argv[1], global);
		global = ft_init(global);
		mlx_hook(global->win_ptr, 2, 1L << 0, &ft_keypress, global);
		mlx_hook(global->win_ptr, 17, 1L << 17, &ft_mousepress, global);
		global->addr = mlx_get_data_addr(global->image, &global->bit_p_p,
				&global->l_l, &global->endian);
		ft_crea_pix(global);
		open_img(global);
		// global->image = mlx_xpm_file_to_image(global->mlx_ptr, "xpm/sora_bas.XPM", &x, &y);
		mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->image, global->pl->pos_x, global->pl->pos_y);
		//mlx_loop_hook(global->mlx, , void(*)&global);
		mlx_loop(global->mlx_ptr);
		if (global)
			free(global);
		if (global->pixel)
			free(global->pixel);
		if (global->map)
			free(global->map);
	}
}
