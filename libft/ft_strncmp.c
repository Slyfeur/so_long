/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 08:21:36 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:23:30 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	unsigned int		i;

	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	i = 0;
	while (p_s1[i] == p_s2[i] && p_s1[i] != '\0' && i < n)
		i++;
	if (i == n)
		return (0);
	return (p_s1[i] - p_s2[i]);
}
