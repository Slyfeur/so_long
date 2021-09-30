/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:23:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/30 15:07:56 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	crea_tab2(t_so_long *global, int i, int j, char *line)
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
	return (j);
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
			j = crea_tab2(global, i, j, line);
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
		global->map->tab[i] = (char *)
			malloc((global->w_map + 1) * sizeof(char));
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
