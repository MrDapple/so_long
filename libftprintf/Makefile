SRCS		:=	ft_printf.c \
				ft_printf_char.c \
				ft_printf_nb.c \
				ft_printf_str.c \
				ft_printf_void.c \
				ft_printf_unsigned.c \
				ft_printf_lower_hex.c \
				ft_printf_upper_hex.c \

LIBFT		:= libft/libft.a \

NAME		:=	libftprintf.a
CFLAGS		?=	-Wall -Wextra -Werror
OBJCS		:=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJCS) $(LIBFT)
	ar -rcs $(NAME) $(OBJCS)


$(LIBFT)	:
	make bonus -C libft
	cp $(LIBFT) $(NAME)

clean		:
	rm -f $(OBJCS)
	make clean -C libft

fclean		:	clean
	rm -f $(NAME)
	make fclean -C libft

re			:	fclean all

.PHONY		:	all clean fclean re