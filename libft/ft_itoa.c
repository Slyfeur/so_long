/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:57:08 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/06 11:30:57 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennb(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*valeur;
	int				len;
	long long int	nb;

	nb = n;
	len = ft_lennb(nb);
	valeur = malloc(sizeof(char) * len + 1);
	if (!valeur)
		return (NULL);
	if (nb < 0)
	{
		valeur[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		valeur[0] = '0';
	valeur[len--] = '\0';
	while (nb)
	{
		valeur[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (valeur);
}
