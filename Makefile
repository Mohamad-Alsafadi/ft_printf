NAME = libftprintf.a

SRC_PATH = ./

SRC_NAME =  ft_printf.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_puthex.c\
			ft_putptr.c\
			ft_putuni.c\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)
	@echo "\033[92mLibrary Compiled"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO)
	@echo "\033[93mAll .o Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[95mLibrary Removed"

re:	fclean all

.PHONY: all fclean clean re