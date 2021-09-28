/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:58:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/06 14:52:53 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_realloc(char *str, int to_add)
{
	char	*new;
	int		len;

	len = -1;
	if (str)
		while (str[++len])
			;
	new = malloc(sizeof(char) * (len + to_add));
	if (!new)
		return (NULL);
	if (new)
	{
		len = -1;
		if (str)
			while (str[++len])
				new[len] = str[len];
		new[len] = 0;
	}
	free(str);
	str = NULL;
	return (new);
}
