CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_put.c ft_put_hexa.c ft_putmem.c ft_putmem.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^
	
clean : 
	rm -f $(OBJ) $(BOBJ)
    
fclean : clean
	rm -f $(NAME)
    
re : fclean all
