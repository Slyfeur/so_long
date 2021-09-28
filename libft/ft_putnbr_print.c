/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:51:43 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/11 09:36:04 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_print(t_struct *tab, int n)
{
	char	str;

	str = 0;
	ft_nbr(tab, n, str);
}

void	ft_putu_print(t_struct *tab)
{
	unsigned long	u2;
	char			*str;

	str = ft_itoa(tab->u);
	u2 = 0;
	if (tab->u < 0)
	{
		u2 = tab->u;
		tab->u = 4294967296 - u2;
	}
	else if (tab->u > 4294967295)
	{
		u2 = tab->u - 4294967295;
		tab->u = 0 + u2;
	}
	write(1, &*str, ft_strlenprint(str));
	tab->tl += ft_strlenprint(str);
	free(str);
}

void	ft_writemoins(t_struct *tab)
{
	if (tab->pluspetit0 == 1)
	{
		if (tab->pluspetit0 == 1 && !(tab->di == 2147483648))
		{
			write(1, "-", 1);
			tab->tl += 1;
			tab->pluspetit0 = 0;
		}
	}
}

void	ft_change(t_struct *tab)
{
	char	*c;

	tab->pluspetit0 = 1;
	if (tab->di)
	{
		c = ft_itoa(tab->di);
		c[0] = '0';
		tab->di = ft_atoi(c);
	}
	if (tab->u)
	{
		c = ft_itoa(tab->u);
		c[0] = '0';
		tab->u = ft_atoi(c);
	}
	free(c);
}

void	ft_nbr(t_struct *tab, int n, char str)
{
	if (n == -2147483648)
	{
		ft_putnbr_print(tab, n / 10);
		write(1, "8", 1);
		tab->tl += 1;
		return ;
	}
	else if (n < 0)
	{
		if (tab->pluspetit0 == 1)
		{
			write(1, "-", 1);
			tab->tl += 1;
		}
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_print(tab, n / 10);
		str = n % 10 + '0';
	}
	else
		str = n + '0';
	write(1, &str, 1);
	tab->tl += ft_numlen(str) - 1;
}
