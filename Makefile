SRCS		:=	SL_utils.c \
				SL_gentab.c \
				SL_movement.c \
				SL_calc.c \

LIBPRINT	:= libftprintf/libftprintf.a

MINILIBX	:= minilibx/libmlx.a

NAME		:=	so_long.a
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:= -framework OpenGL -framework AppKit
OBJCS		:=	$(SRCS:.c=.o)

all			:	libft mlx $(NAME)

$(NAME)		:	$(OBJCS)

# %.o			:	%.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

libft		:
	@make -C libftprintf

mlx	:
	@make -C minilibx

clean		:
	@rm -f *.o
	@make clean -C libftprintf
	@make clean -C minilibx

fclean		:	clean
	@make fclean -C libftprintf
	@rm -f $(NAME) libmlx.a libftprintf.a

re			:	fclean all

run			:	all
	@echo "\n-------------- RESULT --------------"
	@gcc $(CFLAGS) $(SFLAGS) $(OBJCS) $(MINILIBX) $(LIBPRINT) && ./a.out | cat -e
	@echo "------------------------------------\n"
	@echo "cleaning up...\n"
	@rm -f *.o

.PHONY		:	all clean fclean re run