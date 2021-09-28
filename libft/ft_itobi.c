/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:26:56 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/26 10:33:39 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	itobi(int x)
{
	long long	r;
	long long	binaire;
	long long	temp;

	binaire = 0;
	temp = 1;
	while (x != 0)
	{
		r = x % 2;
		binaire = binaire + r * temp;
		temp = temp * 10;
		x = x / 2;
	}
	return (binaire);
}
