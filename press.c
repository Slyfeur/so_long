/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:50 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 09:22:09 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, void *param)
{
	t_so_long	*glo;

	glo = (t_so_long *)param;
	if (keycode == 53)
	{
		ft_free_all(glo);
		//system("leaks so_long");
		exit(0);
	}
	else if ((keycode == 125 || keycode == 1)
		&& (glo->pl->pos_y < glo->height - 32)
		&& glo->map->tab[(glo->pl->pos_y / 32) + 1][glo->pl->pos_x / 32] != '1')
		m_bas(glo);
	else if ((keycode == 124 || keycode == 2)
		&& (glo->pl->pos_x < glo->width - 32)
		&& glo->map->tab[glo->pl->pos_y / 32][(glo->pl->pos_x / 32) + 1] != '1')
		m_droite(glo);
	else if ((keycode == 126 || keycode == 13) && (glo->pl->pos_y > 31)
		&& glo->map->tab[(glo->pl->pos_y / 32) - 1][glo->pl->pos_x / 32] != '1')
		m_haut(glo);
	else if ((keycode == 123 || keycode == 0) && (glo->pl->pos_x > 31)
		&& glo->map->tab[glo->pl->pos_y / 32][(glo->pl->pos_x / 32) - 1] != '1')
		m_gauche(glo);
	return (0);
}

int	ft_mousepress(void *param)
{
	t_so_long	*glo;

	glo = (t_so_long *)param;
	ft_free_all(glo);
	//system("leaks so_long");
	exit(0);
}
