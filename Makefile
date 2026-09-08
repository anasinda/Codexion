NAME = codexion

SRCS = src/main.c \
       src/parsing/parse_args.c \
       src/parsing/parse_utils.c \
       src/coder/coder_allocation.c \
       src/coder/coder_init.c \
       src/coder/coder_routine.c \
       src/dongle/dongle_allocation.c \
       src/dongle/dongle_init.c \
       src/dongle/dongle_acquire.c \
       src/dongle/dongle_release.c \
       src/scheduler/heap_init.c \
       src/scheduler/heap_push.c \
       src/scheduler/heap_pop.c \
       src/utils/logger.c \
       src/utils/simulator_init.c \
       src/utils/time_utils.c \
       src/scheduler/heap_peak.c

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
DEBUG = -g
HEADER = -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(DEBUG) $(FLAGS) $(HEADER) -c $< -o $@

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 3 800 200 200 200 2 50 fifo

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
