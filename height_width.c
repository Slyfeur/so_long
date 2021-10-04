/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:56:52 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 08:43:55 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *filename, t_so_long *glo)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(glo, "Open failed");
	glo->h_map = 0;
	while (get_next_line(fd, &line) > 0)
	{
		glo->h_map++;
		free(line);
	}
	free(line);
	if (glo->h_map < 2)
		ft_error(glo, "Map invalid");
	glo->h_map++;
	if (close(fd) != 0)
		ft_error(glo, "Close failed");
	return (glo->h_map);
}

int	get_width(char *filename, t_so_long *glo)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(glo, "Open failed");
	i = 0;
	glo->w_map = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error(glo, "Map invalid");
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i + 1] == ' ' || line[i] == '\0'))
			glo->w_map++;
		i++;
	}
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) != 0)
		ft_error(glo, "Close failed");
	return (glo->w_map);
}
