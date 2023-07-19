SRCS		:=	testmain.c

LIBPRINT	:= libft/libft.a \

NAME		:=	so_long
CFLAGS		?=	-Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(LIBPRINT) $(MLX)

$(LIBPRINT)	:
	make -C libftprintf

$(MLX)		:
	make -C minilibx

clean		:
	make clean -C libft

fclean		:	clean
	rm -f $(NAME)
	make fclean -C libft

re			:	fclean all

run			:
		@cc $(CFLAGS) -c -o testmain.o testmain.c
		@echo "\n-------------- RESULT --------------"
		@gcc -Wall -Wextra -Werror *.o -L. ./libftprintf/libftprintf.a minilibx/mlx.h && time ./a.out | cat -e
		@echo "------------------------------------\n"
		@echo "cleaning up...\n"
		@rm -fr testmain.o

.PHONY		:	all clean fclean re