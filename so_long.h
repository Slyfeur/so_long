/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:04:40 by tuytters          #+#    #+#             */
/*   Updated: 2021/10/04 13:05:57 by tuytters         ###   ########.fr       */
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
	int	x;
}	t_pixel;

typedef struct s_count
{
	int	p;
	int	c;
	int	e;
	int	o;
	int	move;
	int	img_to_wind;
	int	init_tab;
}	t_count;

typedef struct s_pl
{
	int		pos_x;
	int		pos_y;
	void	*s_b;
	void	*s_h;
	void	*s_d;
	void	*s_g;
	int		di;
}	t_pl;

typedef struct s_map
{
	char	**tab;
	void	*bloc;
	void	*exit;
	void	*sol;
	void	*m_b;
	void	*m_b_g;
	void	*m_b_d;
	void	*m_g;
	void	*m_d;
	void	*m_h;
	void	*m_h_g;
	void	*m_h_d;
}	t_map;

typedef struct s_c
{
	void	*k0;
	void	*k1;
	void	*k2;
	void	*k3;
	void	*k4;
	void	*k5;
	void	*k6;
	void	*k7;
	void	*k8;
	void	*k9;
	void	*k10;
	void	*k11;
	void	*k12;
	void	*k13;
	void	*k14;
	void	*k15;
	void	*k16;
	int		nbr;
}	t_c;

typedef struct s_o
{
	int		pos_x;
	int		pos_y;
	void	*o_b;
	void	*o_h;
	void	*o_d;
	void	*o_g;
}	t_o;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*addr;
	int			l_l;
	int			bit_p_p;
	int			endian;
	int			height;
	int			h_map;
	int			width;
	int			w_map;
	int			init;
	t_pixel		*pixel;
	t_map		*map;
	t_pl		*pl;
	t_count		*count;
	t_c			*c;
	t_o			*o;
}	t_so_long;

void	ft_crea_pix(t_so_long *glo);
void	ft_crea(t_so_long *glo);
int		ft_keypress(int keycode, void *param);
int		ft_mousepress(void *param);
void	parse(char *filename, t_so_long *glo);
void	ft_error(t_so_long *glo, char *msg_error);
void	open_img(t_so_long *glo);
void	check_error_map(t_so_long *glo);
void	check_error_parsing(char *filename, t_so_long *glo);
void	check_error_wall(t_so_long *glo);
int		get_height(char *filename, t_so_long *glo);
int		get_width(char *filename, t_so_long *glo);
void	pr_img_to_wind(t_so_long *glo);
void	m_bas(t_so_long *glo);
void	m_haut(t_so_long *glo);
void	m_gauche(t_so_long *glo);
void	m_droite(t_so_long *glo);
void	pr_mess(t_so_long *glo, int i);
void	pr_w_to_im(t_so_long *glo, int i, int j);
void	pr_exit_to_im(t_so_long *glo, int i, int j);
void	pr_ground_to_im(t_so_long *glo, int i, int j);
void	pr_move(t_so_long *glo);
void	ft_free_all(t_so_long *glo);
void	destroy_p_and_m_img(t_so_long *glo);
void	destroy_c_img(t_so_long *glo);
void	opponent_move(t_so_long *glo);

#endif