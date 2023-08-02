

SRCS		:=	ft_atoi.c \
				ft_isalpha.c \
				ft_isprint.c \
				ft_strchr.c \
				ft_strlen.c \
				ft_strrchr.c \
				ft_isascii.c \
				ft_strncmp.c \
				ft_tolower.c \
				ft_isalnum.c \
				ft_isdigit.c \
				ft_strlcpy.c \
				ft_toupper.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strlcat.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_split.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_printf.c \
				ft_printf_char.c \
				ft_printf_nb.c \
				ft_printf_str.c \
				ft_printf_void.c \
				ft_printf_unsigned.c \
				ft_printf_lower_hex.c \
				ft_printf_upper_hex.c \

NAME		:=	libftprintf.a
CFLAGS		?=	-Wall -Wextra -Werror
OBJCS		:=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJCS)
	ar -rcs $(NAME) $(OBJCS)

clean		:
	rm -f $(OBJCS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re