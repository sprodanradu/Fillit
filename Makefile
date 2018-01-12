NAME = fillit

SRCS = srcs/aff_matrix.c srcs/checker.c srcs/fillit.c srcs/main.c srcs/utility.c

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

re: fclean all