CFILES	= $(filter-out $(wildcard *_bonus.c), $(wildcard *.c))
OBJS	= $(CFILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar vcrs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
