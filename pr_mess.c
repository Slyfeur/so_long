/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_mess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:18:24 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 15:28:18 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pr_mess(t_so_long *glo, int i)
{
	if (i == 0)
	{
		ft_printf("You win in %d moves, congratulation!\n", glo->count->move);
		ft_free_all(glo);
		//system("leaks so_long");
		exit (0);
	}
	if (i == 1)
	{
		ft_printf("You are dead, try again!!!\n");
		ft_free_all(glo);
		//system("leaks so_long");
		exit (0);
	}
}

void	pr_move(t_so_long *glo)
{
	char	*mve;

	mve = ft_itoa(glo->count->move);
	mlx_put_image_to_window(glo->mlx, glo->win, glo->map->m_h_g, 0, 0);
	if (glo->count->move >= 100)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->m_h, 32, 0);
	if (glo->count->move >= 100000)
		mlx_put_image_to_window(glo->mlx, glo->win, glo->map->m_h, 64, 0);
	mlx_string_put(glo->mlx, glo->win, 10, 10, 0x00FF0000, mve);
	free(mve);
}
