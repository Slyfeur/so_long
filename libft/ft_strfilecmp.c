/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:03:26 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 09:21:23 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfilecmp(char *file, char *end)
{
	int	file_len;
	int	end_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	file_len = ft_strlen(file);
	end_len = ft_strlen(end);
	i = file_len - end_len;
	while (file[i])
	{
		if (file[i] != end[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}
