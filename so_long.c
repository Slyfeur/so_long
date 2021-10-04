/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:21:33 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 12:37:48 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_so_long	*ft_init(t_so_long *glo)
{
	glo->mlx = mlx_init();
	glo->win = mlx_new_window(glo->mlx,
			glo->width, glo->height, "So_long");
	glo->image = mlx_new_image(glo->mlx,
			glo->height, glo->width);
	glo->init = 1;
	return (glo);
}

void	ft_init_nbr(t_so_long *glo)
{
	glo->count->p = 0;
	glo->count->e = 0;
	glo->count->c = 0;
	glo->count->o = 0;
	glo->count->move = 0;
	glo->pl->di = 1;
}

static t_so_long	*ft_malloc_all(t_so_long *glo)
{
	t_pixel		*pixel;
	t_map		*map;
	t_pl		*pl;
	t_count		*count;
	t_c			*c;
	t_o			*o;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		ft_error(glo, "Malloc failed");
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(glo, "Malloc failed");
	pl = malloc(sizeof(t_pl));
	if (!pl)
		ft_error(glo, "Malloc failed");
	c = malloc(sizeof(t_c));
	if (!c)
		ft_error(glo, "Malloc failed");
	count = malloc(sizeof(t_count));
	if (!pl)
		ft_error(glo, "Malloc failed");
	o = malloc(sizeof(t_o));
	if (!o)
		ft_error(glo, "Malloc failed");
	glo->pl = pl;
	glo->map = map;
	glo->pixel = pixel;
	glo->count = count;
	glo->c = c;
	glo->o = o;
	ft_init_nbr(glo);
	return (glo);
}

int	main(int argc, char **argv)
{
	t_so_long	*glo;

	if (argc == 2 && ft_strfilecmp(argv[1], ".ber") == 0)
	{
		glo = malloc(sizeof(t_so_long));
		if (!glo)
			ft_error(glo, "Malloc failed");
		ft_malloc_all(glo);
		parse(argv[1], glo);
		check_error_map(glo);
		glo = ft_init(glo);
		mlx_hook(glo->win, 2, 1L << 0, &ft_keypress, glo);
		mlx_hook(glo->win, 17, 1L << 17, &ft_mousepress, glo);
		glo->addr = mlx_get_data_addr(glo->image, &glo->bit_p_p,
				&glo->l_l, &glo->endian);
		open_img(glo);
		pr_img_to_wind(glo);
		mlx_loop(glo->mlx);
	}
	else
	{
		ft_printf("Wrong map name");
		exit (-1);
	}
}
