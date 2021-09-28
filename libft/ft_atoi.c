/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 08:20:31 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/20 14:40:40 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *nptr)
{
	int					signe;
	unsigned long long	valeur;
	int					i;

	signe = 1;
	valeur = 0;
	i = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = signe * -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		valeur = valeur * 10 + (*nptr++ - '0');
		i++;
	}
	if (signe == -1 && (i >= 19 || valeur > (1ull << 63) - 1))
		return (0);
	if (signe == 1 && (i >= 19 || valeur > (1ull << 63) - 1))
		return (-1);
	return (signe * valeur);
}
