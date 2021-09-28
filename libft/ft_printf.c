/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:31:37 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/11 09:32:54 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_initialise_tab(t_struct *tab)
{
	tab->format = 0;
	tab->pourcent = 0;
	tab->s = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	t_struct	*tab;
	int			i;
	int			tl;
	char		*s;

	i = 0;
	tl = 0;
	s = (char *)str;
	va_start(list, str);
	tab = malloc(sizeof(t_struct));
	if (!tab)
		return (0);
	tab->tl = 0;
	ft_baseprint1(tab, list, s, i);
	va_end(list);
	tl = tab->tl;
	free(tab);
	return (tl);
}
