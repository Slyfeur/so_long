/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:15:55 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/20 10:51:49 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long n)
{
	long long	count;

	count = 0;
	if (n <= 0)
		count += 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_strlenprint(char *s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

int	ft_strlenhexa(unsigned long long n)
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
	while (i--)
	{
		if (nbr % 16 < 10)
			str[i] = (nbr % 16) + 48;
		else
			str[i] = (nbr % 16) + (97 - 10);
		nbr /= 16;
	}
	str[i] = '\0';
	return (ft_strlen(str));
}

int	ft_binary_len(int n)
{
	int	count;
	int	copy;

	count = 0;
	if (n == 0)
		return (1);
	copy = n;
	while (copy > 0)
	{
		count++;
		copy /= 2;
	}
	return (count);
}
