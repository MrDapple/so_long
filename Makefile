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
	$(CC) $(OBJCS) $(LIBPRINT) -lmlx $(SFLAGS) -o $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

libft		:
	@make -C libftprintf

clean		:
	@rm -f *.o

fclean		:	clean
	make fclean -C libftprintf
	rm -f $(NAME) $(LIBPRINT)

re			:	fclean all

run			:	all
	@echo "\n-------------- RESULT --------------"
	@gcc $(CFLAGS) $(SFLAGS) $(OBJCS) $(LIBPRINT) && ./a.out | cat -e
	@echo "------------------------------------\n"
	@echo "cleaning up...\n"
	@rm -f *.o a.out

push		: 	fclean
	@echo "\n$(RED)= = = = = [UPDATING] = = = = =$(BLACK)\n\n"
	@git status
	@echo "$(BLUE)		- - -	ADD CHANGES....	- - - $(BLACK)\n\n"
	@git add -A
	@echo " $(GREEN)		- - -	ADD CHANGES OK!	- - - $(NC)\n\n"
	@echo "$(BLUE)		- - -	COMMITING....	- - - $(BLACK)\n\n"
	@git commit -m "automatic update"
	@echo " $(GREEN)		- - -	COMMIT OK!	- - - $(NC)\n\n"
	@echo "$(BLUE)		- - -	PUSHING....	- - - $(BLACK)\n\n"
	@git push
	@echo " $(GREEN)		 - - -	PUSH OK!	- - - $(NC)\n\n"
	@echo "\n$(GREEN)= = = = = [UPDATE OK!] = = = = =$(NC)\n\n"

.PHONY		:	all clean fclean re libft mlx run