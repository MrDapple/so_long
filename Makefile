SRCS		:=	SL_utils.c \
				SL_gentab.c \
				SL_movement.c \
				SL_calc.c \
				SL_checkmap.c \

LIBPRINT	:= libftprintf/libftprintf.a

MINILIBX	:= minilibx/libmlx.a

NAME		:=	so_long.a
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:= -framework OpenGL -framework AppKit
OBJCS		:=	$(SRCS:.c=.o)

all			:	libft mlx $(NAME)

$(NAME)		:	$(OBJCS)

.c.o		:
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

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
	@rm -f *.o a.out

.PHONY		:	all clean fclean re run