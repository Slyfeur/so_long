/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:57:37 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:21:14 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	unsigned char		e;

	p_dest = dst;
	p_src = src;
	e = (unsigned char)c;
	while (n)
	{
		if (*p_src != e)
		{
			*p_dest = *p_src;
			p_dest++;
			p_src++;
			n--;
		}
		else if (*p_src == e)
		{
			*p_dest = *p_src;
			return (p_dest + 1);
			break ;
		}
	}
	return (NULL);
}
