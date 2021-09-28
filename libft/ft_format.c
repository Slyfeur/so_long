/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:38:39 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:17:32 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formatnum(va_list list, t_struct *tab, char *str, int i)
{	
	if (str[i] == 'd' || str[i] == 'i')
	{
		tab->format = 1;
		tab->di = va_arg(list, int);
		if (tab->di < 0)
			ft_change(tab);
	}
	if (str[i] == 'x')
	{
		tab->format = 2;
		tab->x = va_arg(list, unsigned int);
	}
	if (str[i] == 'X')
	{
		tab->format = 3;
		tab->x_maj = va_arg(list, unsigned int);
	}
	if (str[i] == 'p')
	{
		tab->format = 4;
		tab->p = va_arg(list, unsigned long long);
	}
	i++;
	return (i);
}

int	ft_formatuchar(va_list list, t_struct *tab, char *str, int i)
{
	if (str[i] == 'u')
	{
		tab->format = 5;
		tab->u = va_arg(list, unsigned int);
		if (tab->u < 0)
			ft_change(tab);
	}
	if (str[i] == 'c')
	{
		tab->format = 6;
		tab->c = va_arg(list, int);
	}
	if (str[i] == 's')
	{
		tab->format = 7;
		tab->s = va_arg(list, char *);
		if (!tab->s)
			tab->s = "(null)";
	}
	i++;
	return (i);
}
