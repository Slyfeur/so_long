/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:23:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:03:34 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *filename, t_so_long *global)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nOpen failed\n");
	global->height_map = 0;
	while (get_next_line(fd, &line) > 0)
	{
		global->height_map++;
		free(line);
	}
	if (global->height_map < 2)
		ft_error("Error\nMap invalid\n");
	global->height_map++;
	free(line);
	if (close(fd) != 0)
		ft_error("Error\nClose failed\n");
	return (global->height_map);
}

int	get_width(char *filename, t_so_long *global)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nOpen failed\n");
	i = 0;
	global->width_map = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error("Error\nMap invalid\n");
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i + 1] == ' ' || line[i] == '\0'))
			global->width_map++;
		i++;
	}
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) != 0)
		ft_error("Error\nClose failed\n");
	return (global->width_map);
}

void	crea_tab(char *filename, t_so_long *global)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nOpen failed\n");
	i = 0;
	while (i <= global->height_map)
	{
		j = 0;
		get_next_line(fd, &line);
		while (line[j] != '\0')
		{
			global->map->tab[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	if (close(fd) != 0)
		ft_error("Error\nClose failed\n");
}

int	ft_init_tab(t_so_long *global)
{
	int	i;

	global->map->tab = (char **) malloc(global->height_map * sizeof(char *));
	if (!global->map->tab)
		ft_error("Error\nMalloc failed\n");
	i = 0;
	while (i < global->height_map)
	{
		global->map->tab[i] = (char *) malloc(global->width_map * sizeof(char));
		if (!global->map->tab[i])
		{
			free(global->map->tab);
			ft_error("Error\nMalloc failed\n");
		}
		i++;
	}
	return (0);
}

void	parse(char *filename, t_so_long *global)
{
	global->height = 32 * get_height(filename, global);
	global->width = 32 * get_width(filename, global);
	ft_init_tab(global);
	crea_tab(filename, global);
}
