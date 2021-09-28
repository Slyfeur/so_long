/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:26:31 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:21:18 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_s;
	unsigned char		e;

	p_s = s;
	e = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p_s == e)
			return ((void *) p_s);
		p_s++;
	}
	return (0);
}
