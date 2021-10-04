/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:23:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 08:47:16 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	crea_tab2(t_so_long *glo, int i, int j, char *line)
{
	glo->map->tab[i][j] = line[j];
	if (line[j] == 'P')
	{
		glo->pl->pos_x = j * 32;
		glo->pl->pos_y = i * 32;
		glo->count->p++;
	}
	if (line[j] == 'E')
		glo->count->e++;
	if (line[j] == 'C')
		glo->count->c++;
	j++;
	return (j);
}

void	crea_tab(char *filename, t_so_long *glo)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(glo, "Open failed");
	i = 0;
	while (i < glo->h_map)
	{
		j = 0;
		get_next_line(fd, &line);
		while (line[j] != '\0')
			j = crea_tab2(glo, i, j, line);
		glo->map->tab[i][j] = '\0';
		free(line);
		i++;
	}
	if (close(fd) != 0)
		ft_error(glo, "Close failed");
}

int	ft_init_tab(t_so_long *glo)
{
	int	i;

	glo->map->tab = (char **) malloc(glo->h_map * sizeof(char *));
	if (!glo->map->tab)
		ft_error(glo, "Malloc failed");
	i = 0;
	while (i < glo->h_map)
	{
		glo->map->tab[i] = (char *)
			malloc((glo->w_map + 1) * sizeof(char));
		if (!glo->map->tab[i])
		{
			free(glo->map->tab);
			ft_error(glo, "Malloc failed");
		}
		i++;
	}
	glo->count->init_tab = 1;
	return (0);
}

void	parse(char *filename, t_so_long *glo)
{
	glo->height = 32 * get_height(filename, glo);
	glo->width = 32 * get_width(filename, glo);
	check_error_parsing(filename, glo);
	ft_init_tab(glo);
	crea_tab(filename, glo);
	check_error_wall(glo);
}
