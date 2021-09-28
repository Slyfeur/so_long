/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:36:55 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:21:38 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	p_dest = (char *)dst;
	p_src = (const char *)src;
	if (dst == '\0' && src == '\0')
		return (0);
	if (p_src <= p_dest)
	{
		p_dest += n - 1;
		p_src += n - 1;
		while (n--)
		{
			*p_dest-- = *p_src--;
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
