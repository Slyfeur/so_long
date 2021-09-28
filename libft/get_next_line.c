/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:05:55 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 09:17:43 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_save(char *buff, char *save, int i)
{
	char	*tmp;

	buff[i] = '\0';
	if (save)
	{
		tmp = ft_strjoingnl(save, buff);
		free(save);
		save = ft_strdupgnl(tmp);
		free(tmp);
	}
	else
		save = ft_strdupgnl(buff);
	return (save);
}

char	*ft_clean(char *save, char **line, int i)
{
	size_t	j;
	char	*tmp;

	j = 0;
	while (save[j])
	{
		if (save[j] == '\n')
			break ;
		j++;
	}
	if (j < ft_strlengnl(save))
	{
		*line = ft_substrgnl(save, 0, j);
		tmp = ft_substrgnl(save, j + 1, ft_strlengnl(save));
		free(save);
		save = ft_strdupgnl(tmp);
		free(tmp);
	}
	else if (i == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	i = read(fd, buff, BUFFER_SIZE);
	while (i)
	{
		if (i < 0)
			return (-1);
		save[fd] = ft_save(buff, save[fd], i);
		if (ft_strchrgnl(buff, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	if (i <= 0 && !save[fd])
	{
		*line = ft_strdupgnl("");
		return (i);
	}
	save[fd] = ft_clean(save[fd], line, i);
	if (i <= 0 && !save[fd])
		return (i);
	return (1);
}
