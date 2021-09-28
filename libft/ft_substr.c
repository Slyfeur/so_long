/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:57:54 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 08:25:16 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*s2;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	n = 0;
	while (n < len && s[start + n] != '\0')
	{
		s2[n] = s[start + n];
		n++;
	}
	s2[n] = '\0';
	return (s2);
}
