/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:04:40 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/29 11:16:48 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "include/mlx.h"
# include "include/libft.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>

typedef struct s_pixel
{
	int	n;
	int	m;
}				t_pixel;

typedef struct s_pl
{
	int	pos_x;
	int	pos_y;
}				t_pl;


typedef struct s_map
{
	char	**tab;
}				t_map;

typedef struct s_so_long
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	char		*addr;
	int			bit_p_p;
	int			l_l;
	int			endian;
	int			height;
	int			h_map;
	int			width;
	int			w_map;
	// int			x;
	// int			y;
	t_pixel		*pixel;
	t_map		*map;
	t_pl	*pl;
}				t_so_long;

void	ft_crea_pix(t_so_long *global);
void	ft_crea(t_so_long *global);
int		ft_keypress(int keycode, void *param);
int		ft_mousepress(void *param);
void	parse(char *filename, t_so_long *global);
void	ft_error(char *msg_error);
void	open_img(t_so_long *global);

#endif