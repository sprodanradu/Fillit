# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 16:42:53 by sprodan-          #+#    #+#              #
#    Updated: 2018/01/12 18:16:11 by sprodan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/check_file.c \
	   srcs/create_vect_of_struct.c \
	   srcs/fillit.c \
	   srcs/main.c \
	   srcs/free_put_matrix.c \
	   srcs/ft_erasespace.c \

OBJ = *.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean
	@make -C libft
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

