OBJCS		:=	SL_utils.o \
				SL_utils_2.o \
				SL_gentab.o \
				SL_movement.o \
				SL_calc.o \
				SL_display_info.o \
				SL_display_info_utils.o \

LIBPRINT	:=	libftprintf.a

NAME		:=	so_long
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=	-framework OpenGL -framework AppKit

all			:	$(NAME)

$(NAME)		:	$(OBJCS)
	$(CC) $(OBJCS) $(LIBPRINT) -lmlx $(CFLAGS) $(SFLAGS) -o $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean		:
	rm -f $(OBJCS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re