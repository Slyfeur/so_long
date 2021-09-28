/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:56:47 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/06 10:41:20 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nombre_mot(char const *s, char c)
{
	size_t	i;
	size_t	m;

	m = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			m++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (m);
}

static size_t	ft_strlen2(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(size_t i, char**dest)
{
	while (i)
		free(dest[--i]);
	free(dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	nbmot;
	size_t	i;

	nbmot = ft_nombre_mot(s, c);
	dest = (char **)malloc(sizeof(char *) * (nbmot + 1));
	if (!dest || !s)
		return (NULL);
	i = 0;
	while (i < nbmot)
	{
		while (s && *s && *s == c)
			s++;
		dest[i] = ft_substr(s, 0, ft_strlen2(s, c));
		if (!dest)
		{
			ft_free(i, dest);
			return (NULL);
		}
		s += ft_strlen2(s, c);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
