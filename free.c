/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:54:11 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 09:22:32 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_tab(t_so_long *glo)
{
	int	i;

	i = 0;
	while (i < glo->h_map)
	{
		free(glo->map->tab[i]);
		i++;
	}
	free(glo->map->tab);
	return (0);
}

void	ft_free_all(t_so_long *glo)
{
	//printf("test\n");
	if (glo->init == 1)
	{
		destroy_p_and_m_img(glo);
		destroy_c_img(glo);
		mlx_destroy_window(glo->mlx, glo->win);
	}
	//printf("test2\n");
	if (glo->pixel)
		free(glo->pixel);
	//printf("test3\n");
	if (glo->c)
		free(glo->c);
	//printf("test4\n");
	if (glo->map)
	{
		if (glo->count->init_tab == 1)
			ft_free_tab(glo);
		free(glo->map);
	}
	//printf("test5\n");
	if (glo->pl)
		free(glo->pl);
	//printf("test6\n");
	if (glo->count)
		free(glo->count);
	if (glo)
		free(glo);
}
