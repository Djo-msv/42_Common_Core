CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	SRC/main.c \
	SRC/algorithm.c \
	SRC/instruction.c \
	SRC/order.c \
	SRC/struct/struct_list.c \
	SRC/struct/struct.c \
	SRC/parsing/parsing.c \
	SRC/parsing/check.c \
	SRC/cmd/swap.c \
	SRC/cmd/push.c \
	SRC/cmd/rotate.c \
	SRC/cmd/reverse_rotate.c \
	SRC/calcule_cost/calculate_cost.c \
	SRC/calcule_cost/calculate_min_cost.c \
	SRC/calcule_cost/up_or_down.c \
#SRC_BONUS =
NAME = push_swap

all: $(NAME)

$(NAME) : $(SRC)
	@echo "\033[33m----Compiling lib----"
	@make -C ./Includes/libft
	
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
	$(CC) $(CFLAGS) $^ -o $(NAME) -I Includes/push_swap.h  -L./Includes/libft -lft

clean : 
	@make clean -C ./Includes/libft
	rm -f $(NAME)

fclean : clean
	@make fclean -C ./Includes/libft
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re : fclean all


#bonus : $(SRC_BONUS)
#	@echo "\033[33m----Compiling lib----"
#	@make re -C ./Includes/libft
#	
#	@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
#	$(CC) $(CFLAGS) $^ -L./Includes/libft -lft -o $(NAME)

.PHONY : all clean fclean re bonus
