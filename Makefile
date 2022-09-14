# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slin <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 02:57:13 by slin              #+#    #+#              #
#    Updated: 2022/08/01 02:57:16 by slin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

RM = rm -rf

NAME = so_long

GNL = gnl/

GNSRC = 	$(addprefix $(GNL), \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
)

FT_PRINTF = ft_printf/

PRINT_SRC = $(addprefix $(FT_PRINTF), \
		ft_fonctions1.c ft_fonctions2.c ft_printf.c ft_putchar.c ft_putnbr_hexa_up.c ft_putnbr_hexa.c ft_putnbr.c ft_putstr.c \
)

SRCS = main.c \
		map.c \
		map2.c \
		images.c \
		other.c \
		move.c \
		$(GNSRC) \
		$(PRINT_SRC)

BONUS_SRCS	=	${BONUS}

OBJ	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(SRCS) minilibx/libmlx_Linux.a libft/libft.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re