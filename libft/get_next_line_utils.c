/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:06:31 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/11 10:05:37 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlengnl(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++ != 0)
		size++;
	return (size);
}

char	*ft_strjoingnl(char const *s1, char const *s2)
{
	char	*sfinal;
	size_t	i;
	size_t	j;
	size_t	total;

	if (!s1 || !s2)
		return (ft_strdupgnl(""));
	total = ft_strlengnl(s1) + ft_strlengnl(s2) + 1;
	sfinal = (char *)malloc(total * sizeof(char));
	if (!sfinal)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sfinal[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sfinal[i + j] = s2[j];
		j++;
	}
	sfinal[i + j] = '\0';
	return (sfinal);
}

char	*ft_strdupgnl(const char *s1)
{
	char	*s2;
	size_t	l;
	size_t	i;

	l = ft_strlengnl(s1);
	s2 = (char *)malloc((l + 1) * sizeof(char));
	i = 0;
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}

char	*ft_substrgnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s)
		return (NULL);
	if (start > ft_strlengnl(s))
		return (ft_strdupgnl(""));
	if (len > ft_strlengnl(s))
		s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchrgnl(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
