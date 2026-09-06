NAME = codexion

SRCS = src/main.c src/parsing/parse_args.c src/parsing/parse_utils.c src/coder* src/dongle* src/schedular*
src/utils* src/monitor*

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
HEADER = -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
