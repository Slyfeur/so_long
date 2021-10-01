/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:33:38 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/01 15:59:15 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_so_long *glo, char *msg_error)
{
	ft_free_all(glo);
	ft_printf("Error\n%s\n", msg_error);
	exit (-1);
}

void	check_error_wall(t_so_long *glo)
{
	int	i;
	int	j;

	i = 0;
	while (i < glo->h_map)
	{
		j = 0;
		if (glo->map->tab[i][j] != '1')
			ft_error(glo, "Bad map, left wall with holes");
		if (i == 0 || i == glo->h_map - 1)
		{
			while (glo->map->tab[i][j] != '\0')
			{
				if (glo->map->tab[i][j] != '1')
					ft_error(glo, "Bad map, top or bottom wall with holes");
				j++;
			}
		}
		else
			j = glo->w_map;
		if (glo->map->tab[i][j - 1] != '1')
			ft_error(glo, "Bad map, right wall with holes");
		i++;
	}
}

int	check_error_parsing1(char *line, int j, t_so_long *glo)
{
	if (line[j] != '0' && line[j] != '1' && line[j] != 'E'
		&& line[j] != 'P' && line[j] != 'C')
		ft_error(glo, "Bad map, error character");
	j++;
	return (j);
}

void	check_error_parsing(char *filename, t_so_long *glo)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(glo, "Open failed");
	i = 0;
	while (i++ < glo->h_map)
	{
		j = 0;
		get_next_line(fd, &line);
		while (line[j] != '\0')
			j = check_error_parsing1(line, j, glo);
		if (j != glo->w_map)
			ft_error(glo, "Bad map, the number of characters is not same");
		free(line);
	}
	if (close(fd) != 0)
		ft_error(glo, "Close failed");
}

void	check_error_map(t_so_long *glo)
{
	if (glo->count->p != 1 && glo->count->e != 1 && glo->count->c < 1)
		ft_error(glo, "Wrong number of players, exit and collectible");
	else if (glo->count->p != 1 && glo->count->e != 1)
		ft_error(glo, "Wrong number of players and exit");
	else if (glo->count->p != 1 && glo->count->c < 1)
		ft_error(glo, "Wrong number of players and collectible");
	else if (glo->count->e != 1 && glo->count->c < 1)
		ft_error(glo, "Wrong number of exit and collectible");
	else if (glo->count->p != 1)
		ft_error(glo, "Wrong number of players");
	else if (glo->count->e != 1)
		ft_error(glo, "Wrong number of exit");
	else if (glo->count->c < 1)
		ft_error(glo, "Wrong number of collectible");
}
