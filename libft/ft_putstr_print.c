/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:10:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/08/11 09:36:07 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_print(t_struct *tab, char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		tab->tl += ft_strlenprint(s);
	}
}
