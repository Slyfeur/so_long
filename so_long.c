/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:21:33 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 11:48:39 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_so_long	*ft_init(t_so_long *global)
{
	global->mlx_ptr = mlx_init();
	global->win_ptr = mlx_new_window(global->mlx_ptr,
			global->width, global->height, "So_long");
	global->image = mlx_new_image(global->mlx_ptr,
			global->height, global->width);
	global->pl->s_b = mlx_new_image(global->mlx_ptr,
			32, 32);
	return (global);
}

static t_so_long	*ft_malloc_all(t_so_long *global)
{
	t_pixel		*pixel;
	t_map		*map;
	t_pl		*pl;
	t_count		*count;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		ft_error("Malloc failed");
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Malloc failed");
	pl = malloc(sizeof(t_pl));
	if (!pl)
		ft_error("Malloc failed");
	count = malloc(sizeof(t_pl));
	if (!pl)
		ft_error("Malloc failed");
	global->pl = pl;
	global->map = map;
	global->pixel = pixel;
	global->count = count;
	global->count->p = 0;
	global->count->e = 0;
	global->count->c = 0;
	global->count->move = 0;
	return (global);
}

void	pr_img_to_wind(t_so_long *global)
{
	int	i;
	int	j;
	//int	x;

	i = 0;
	while (i < global->h_map)
	{
		j = 0;
		while (j < global->w_map)
		{
			if (global->map->tab[i][j] == 'P')
			{
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, global->pl->pos_x, global->pl->pos_y);
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->pl->s_b, global->pl->pos_x, global->pl->pos_y);
			}
			else if (global->map->tab[i][j] == '0')
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->sol, j * 32, i * 32);
			else if (global->map->tab[i][j] == '1')
			{
				if (i == 0 && j == 0)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_h_g, j * 32, i * 32);
				else if (i == 0 && j == (global->w_map - 1))
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_h_d, j * 32, i * 32);
				else if (i == 0 && j < global->w_map - 1)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_h, j * 32, i * 32);
				else if (i == global->h_map - 1 && j == 0)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_b_g, j * 32, i * 32);
				else if (i == global->h_map - 1 && j == global->w_map - 1)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_b_d, j * 32, i * 32);
				else if (i > 0 && i < global->h_map - 1 && j == 0)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_g, j * 32, i * 32);
				else if (i > 0 && i < global->h_map - 1 && j == global->w_map - 1)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_d, j * 32, i * 32);
				else if (i == global->h_map - 1 && j < global->w_map - 1)
					mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->m_b, j * 32, i * 32);
				else
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->bloc, j * 32, i * 32);
			}
			else if (global->map->tab[i][j] == 'C')
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->col, j * 32, i * 32);
			else if (global->map->tab[i][j] == 'E')
				mlx_put_image_to_window(global->mlx_ptr, global->win_ptr, global->map->exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_so_long	*global;

	if (argc == 2 && ft_strfilecmp(argv[1], ".ber") == 0)
	{
		global = malloc(sizeof(t_so_long));
		if (!global)
			ft_error("Malloc failed");
		ft_malloc_all(global);
		parse(argv[1], global);
		check_error_map(global);
		global = ft_init(global);
		mlx_hook(global->win_ptr, 2, 1L << 0, &ft_keypress, global);
		mlx_hook(global->win_ptr, 17, 1L << 17, &ft_mousepress, global);
		global->addr = mlx_get_data_addr(global->image, &global->bit_p_p,
				&global->l_l, &global->endian);
		ft_crea_pix(global);
		open_img(global);
		pr_img_to_wind(global);
		//mlx_loop_hook(global->mlx, , void(*)&global);
		mlx_loop(global->mlx_ptr);
		if (global->pixel)
			free(global->pixel);
		if (global->map)
			free(global->map);
		if (global->pl)
			free(global->pl);
		if (global->count)
			free(global->count);
		if (global)
			free(global);
	}
	else
		ft_error("Wrong map name");
}
