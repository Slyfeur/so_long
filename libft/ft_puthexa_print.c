/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:43:17 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:16:13 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa_print(t_struct *tab, unsigned long n)
{
	int				i;
	char			str[40];
	unsigned long	nbr;
	int				size;

	size = 0;
	nbr = n;
	while (n)
		n /= 16 + 0 * size++;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	n = nbr;
	ft_writehexa(tab, i, nbr, str);
	write(1, &str, ft_strlen(str));
	tab->tl += ft_strlenprint(str);
}

void	ft_puthexa_maj_print(t_struct *tab, unsigned long n)
{
	int				i;
	char			str[20];
	unsigned long	nbr;
	int				size;

	size = 0;
	nbr = n;
	while (n)
		n /= 16 + 0 * size++;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	n = nbr;
	ft_writehexa(tab, i, nbr, str);
	write(1, &str, ft_strlen(str));
	tab->tl += ft_strlenprint(str);
}

void	ft_puthexapoint_print(t_struct *tab, unsigned long long n)
{
	int					i;
	char				str[40];
	unsigned long long	nbr;
	int					size;

	size = 0;
	nbr = n;
	while (n)
		n /= 16 + 0 * size++;
	if (!size)
		str[size++] = '0';
	str[size] = '\0';
	i = size;
	n = nbr;
	ft_writehexa(tab, i, nbr, str);
	write(1, "0x", 2);
	tab->tl += 2;
	write(1, &str, ft_strlen(str));
	tab->tl += ft_strlenprint(str);
}

char	*ft_writehexa(t_struct *tab, int i, unsigned long long nbr, char *str)
{
	while (i--)
	{
		if (nbr % 16 < 10)
			str[i] = (nbr % 16) + 48;
		else
		{
			if (tab->format == 3)
				str[i] = (nbr % 16) + (65 - 10);
			else
				str[i] = (nbr % 16) + (97 - 10);
		}
		nbr /= 16;
	}
	str[i] = '\0';
	return (str);
}
