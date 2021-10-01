/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:54:11 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/01 16:11:24 by tuytters         ###   ########.fr       */
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
	if (glo->init == 1)
	{
		destroy_p_and_m_img(glo);
		destroy_c_img(glo);
		mlx_destroy_window(glo->mlx, glo->win);
	}
	if (glo->pixel)
		free(glo->pixel);
	if (glo->c)
		free(glo->c);
	if (glo->map)
	{
		ft_free_tab(glo);
		free(glo->map);
	}
	if (glo->pl)
		free(glo->pl);
	if (glo->count)
		free(glo->count);
	if (glo)
		free(glo);
}
