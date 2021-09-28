/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:37:34 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:18:14 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab(va_list list, t_struct *tab, char *str, int i)
{
	while (tab->format == 0 || str[i] == '\0')
	{
		i++;
		if (!(str[i] == 'd' || str[i] == 'i' || str[i] == 'x'
				|| str[i] == 'X' || str[i] == 'p' || str[i] == 'u'
				|| str[i] == 's' || str[i] == 'c' || str[i] == '%'))
		{
			i++;
		}
		if (str[i] == 'd' || str[i] == 'i' || str[i] == 'x'
			|| str[i] == 'X' || str[i] == 'p')
			ft_formatnum(list, tab, str, i);
		else if (str[i] == 'u' || str[i] == 's' || str[i] == 'c')
			ft_formatuchar(list, tab, str, i);
		else if (str[i] == '%')
			tab->format = 8;
	}
	return (i);
}

void	ft_baseprint1(t_struct *tab, va_list list, char *s, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_initialise_tab(tab);
			i = ft_tab(list, tab, s, i);
			ft_baseprint2(tab);
		}
		else
			ft_putchar_print(tab, s[i]);
		i++;
	}
}

void	ft_baseprint2(t_struct *tab)
{
	ft_writemoins(tab);
	if (tab->format == 1)
		ft_putnbr_print(tab, tab->di);
	else if (tab->format == 5)
		ft_putu_print(tab);
	else if (tab->format == 7)
		ft_putstr_print(tab, tab->s);
	else if (tab->format == 6)
		ft_putchar_print(tab, tab->c);
	else if (tab->format == 4)
		ft_puthexapoint_print(tab, tab->p);
	else if (tab->format == 2)
		ft_puthexa_print(tab, tab->x);
	else if (tab->format == 3)
		ft_puthexa_maj_print(tab, tab->x_maj);
	else if (tab->format == 8)
	{
		write(1, "%", 1);
		tab->tl++;
	}
}
