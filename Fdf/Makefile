CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC =	SRC/main.c \
	SRC/utils.c \
	SRC/hook.c \
	SRC/algorithm/raytrace.c \
	SRC/algorithm/projection.c \
	SRC/algorithm/render.c \
	SRC/parsing/parsing.c \
	SRC/struct/create_struct.c
SRC_BONUS =
NAME = fdf
LIB = https://github.com/seekrs/MacroLibX.git

all: $(NAME)

$(NAME) : $(SRC)
#	@git clone https://github.com/seekrs/MacroLibX.git Includes/MacroLibX
#	@make ./Includes/MacroLibX
	@echo "\033[33m----Compiling lib----"
	@make -C ./Includes/libft
	@echo "\033[32mLib Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
	
	@echo "\033[33m----Compiling FdF----"
	$(CC) $(CFLAGS) $^ -L./Includes/libft -lft ./Includes/MacroLibX/libmlx.so -lSDL2 -o $(NAME) -lm
	@echo "\033[32mFdf Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean :
	@make clean -C ./Includes/libft


fclean : clean
	@rm -f $(NAME)
	#@rm -rf ./Includes/MacroLibX
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re : fclean all

bonus : $(SRC_BONUS)
	@echo "\033[33m----Compiling lib----"
	@make re -C ./Includes/libft
	
	@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
	$(CC) $(CFLAGS) $^ -L./Includes/libft -lft L./Includes/MacroLibX -lmlx -o $(NAME)

.PHONY : all clean fclean re bonus
