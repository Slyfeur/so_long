/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:33:38 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 15:40:42 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg_error)
{
	ft_printf("Error\n%s\n", msg_error);
	exit (-1);
}

void	check_error_wall(t_so_long *global)
{
	int	i;
	int	j;
//	int	x;

	i = 0;
//	x = 0;
	while (i < global->h_map)
	{
		j = 0;
		printf("test %p\n", global->map->tab);
		if (global->map->tab[i][j] != '1')
			ft_error("Bad map, left wall with holes");
		printf("test1\n");
		if (i == 0 || i == global->h_map - 1)
		{
			while (global->map->tab[i][j] != '\0')
			{
				printf("test2\n");
				if (global->map->tab[i][j] != '1')
					ft_error("Bad map, top or bottom wall with holes");
				j++;
			}
		}
		else
			j = global->w_map;
		printf("test3\n");
		printf("j = %d width = %d\n", j, global->w_map);
		if (global->map->tab[i][j - 1] != '1')
			ft_error("Bad map, right wall with holes");
		i++;
	}
}

void	check_error_parsing(char *filename, t_so_long *global)
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
			if (line[j] != '0' && line[j] != '1' && line[j] != 'E'
				&& line[j] != 'P' && line[j] != 'C')
				ft_error("Bad map, error character");
			j++;
		}
		if(j != global->w_map)
			ft_error("Bad map, not the same number of characters in the lines");
		free(line);
		i++;
	}
	if (close(fd) != 0)
		ft_error("Close failed");
}

void	check_error_map(t_so_long *global)
{
	if (global->count->p != 1)
		ft_error("Wrong number of players");
	else if (global->count->e != 1)
		ft_error("Wrong number of exit");
	else if (global->count->c < 1)
		ft_error("Wrong number of collectible");
}