# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 11:38:38 by tuytters          #+#    #+#              #
#    Updated: 2021/09/28 13:35:59 by tuytters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT		=	libft/
MLX			=	minilibx/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE) -fsanitize=address -g
RM			=	rm -f
SRCS		=	so_long.c	\
				error.c		\
				parsing.c	\
				pixel.c		\
				press.c

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean	:
				@$(RM) $(OBJS)
				@make clean -C ./libft/

fclean	:		clean
				@$(RM) $(NAME)
				@make fclean -C ./libft/

re		:		fclean all
.PHONY	:		all clean fclean re	test bonus