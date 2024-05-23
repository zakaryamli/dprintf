SRC =	ft_printf.c	ft_putchar.c	ft_putnbr.c	ft_putstr.c	ft_puthex.c	ft_putptr.c	ft_putunsigned.c
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.PHONY: all clean fclean re

