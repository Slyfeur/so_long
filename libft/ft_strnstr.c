/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:19:23 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:23:44 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(char *s1, char *s2)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;

	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	while (*p_s1 != '\0' && *p_s2 != '\0')
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
	}
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*x;
	char	*y;

	x = (char *)s1;
	y = (char *)s2;
	j = ft_strlen(s2);
	if (s2[0] == '\0')
		return (x);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0] && i + j <= n)
		{
			if (ft_strcmp((x + i), y) == 0)
			{
				return (x + i);
			}
		}
		i++;
	}
	return (NULL);
}
