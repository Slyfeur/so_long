/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:23:07 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 11:15:55 by tuytters         ###   ########.fr       */
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
	global->h_map = 0;
	while (get_next_line(fd, &line) > 0)
	{
		global->h_map++;
		free(line);
	}
	if (global->h_map < 2)
		ft_error("Error\nMap invalid\n");
	global->h_map++;
	free(line);
	if (close(fd) != 0)
		ft_error("Error\nClose failed\n");
	return (global->h_map);
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
	global->w_map = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error("Error\nMap invalid\n");
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
		ft_error("Error\nClose failed\n");
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
		ft_error("Error\nOpen failed\n");
	i = 0;
	//printf("h_map=%d\n", global->h_map);
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
				//printf("pos_x = %d pos_y = %d\n", global->player->pos_x, global->player->pos_y);
			}
			j++;
		}
		global->map->tab[i][j] = '\0';
		// j = 0;
		// while (global->map->tab[i][j])
		// {
		// 	printf("%c", global->map->tab[i][j]);
		// 	j++;
		// }
		// printf("\n");
		free(line);
		i++;
	}
	if (close(fd) != 0)
		ft_error("Error\nClose failed\n");
}

int	ft_init_tab(t_so_long *global)
{
	int	i;

	global->map->tab = (char **) malloc(global->h_map * sizeof(char *));
	if (!global->map->tab)
		ft_error("Error\nMalloc failed\n");
	i = 0;
	while (i < global->h_map)
	{
		global->map->tab[i] = (char *) malloc((global->w_map + 1) * sizeof(char));
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
