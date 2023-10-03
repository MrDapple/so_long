OBJCS		:=	SL_utils.o \
				SL_utils_2.o \
				SL_gentab.o \
				SL_movement.o \
				SL_calc.o \

LIBPRINT	:= libftprintf/libftprintf.a

NAME		:=	so_long
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=	-framework OpenGL -framework AppKit

all			:	libft $(NAME)

$(NAME)		:	$(OBJCS)
	$(CC) $(OBJCS) $(LIBPRINT) -lmlx $(CFLAGS) $(SFLAGS) -o $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

libft		:
	make -C libftprintf

clean		:
	rm -f $(OBJCS)

fclean		:	clean
	make fclean -C libftprintf
	rm -f $(LIBPRINT) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re libft