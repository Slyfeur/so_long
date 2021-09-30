# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 09:45:55 by tuytters          #+#    #+#              #
#    Updated: 2021/09/30 09:22:23 by tuytters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_itobi.c		\
			ft_len.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strfilecmp.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_format.c				\
			ft_printf.c				\
			ft_putchar_print.c		\
			ft_puthexa_print.c		\
			ft_putnbr_print.c		\
			ft_putstr_print.c		\
			ft_tab.c				\
			ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c		\
			ft_realloc.c		\
			get_next_line_utils.c	\
			get_next_line.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a
LIB		=	libft.h

CLEAN	=	clean

all	:		$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) -c -I$(LIB) $(CFLAGS) $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all
.PHONY	:	all clean fclean re	test
