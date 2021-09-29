/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:23:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 15:17:00 by tuytters         ###   ########.fr       */
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

void	crea_tab(char *filename, t_so_long *global)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed");
	i = 0;
	while (i < global->h_map)
	{
		j = 0;
		get_next_line(fd, &line);
		while (line[j] != '\0')
		{
			global->map->tab[i][j] = line[j];
			if (line[j] == 'P')
			{
				global->pl->pos_x = j * 32;
				global->pl->pos_y = i * 32;
				global->count->p++;
			}
			if (line[j] == 'E')
				global->count->e++;
			if (line[j] == 'C')
				global->count->c++;
			j++;
		}
		global->map->tab[i][j] = '\0';
		free(line);
		i++;
	}
	if (close(fd) != 0)
		ft_error("Close failed");
}

int	ft_init_tab(t_so_long *global)
{
	int	i;

	global->map->tab = (char **) malloc(global->h_map * sizeof(char *));
	if (!global->map->tab)
		ft_error("Malloc failed");
	i = 0;
	while (i < global->h_map)
	{
		global->map->tab[i] = (char *) malloc((global->w_map + 1) * sizeof(char));
		if (!global->map->tab[i])
		{
			free(global->map->tab);
			ft_error("Malloc failed");
		}
		i++;
	}
	return (0);
}

void	parse(char *filename, t_so_long *global)
{
	global->height = 32 * get_height(filename, global);
	global->width = 32 * get_width(filename, global);
	check_error_parsing(filename, global);
	ft_init_tab(global);
	crea_tab(filename, global);
	check_error_wall(global);
}
