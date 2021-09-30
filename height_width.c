/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:56:52 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 15:08:20 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *filename, t_so_long *global)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed");
	global->h_map = 0;
	while (get_next_line(fd, &line) > 0)
	{
		global->h_map++;
		free(line);
	}
	if (global->h_map < 2)
		ft_error("Map invalid");
	global->h_map++;
	free(line);
	if (close(fd) != 0)
		ft_error("Close failed");
	return (global->h_map);
}

int	get_width(char *filename, t_so_long *global)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed");
	i = 0;
	global->w_map = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error("Map invalid");
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i + 1] == ' ' || line[i] == '\0'))
			global->w_map++;
		i++;
	}
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) != 0)
		ft_error("Close failed");
	return (global->w_map);
}
