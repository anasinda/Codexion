NAME = codexion

SRCS = src/main.c \
       src/parsing/parse_args.c \
       src/parsing/parse_utils.c \
       src/coder/coder_init.c \
       src/coder/coder_routine.c \
       src/dongle/dongle_init.c \
       src/dongle/dongle_utils.c \
       src/scheduler/heap_init.c \
       src/scheduler/heap_push.c \
       src/requests/ensure_queued.c \
       src/requests/queuing_request.c \
       src/requests/request_functions.c \
       src/requests/try_to_pair.c \
       src/monitor/monitor.c \
       src/monitor/monitor_utils.c \
       src/simulation/simulation_utils.c \
       src/simulation/simulator_init.c \
       src/utils/check_fail_cases.c \
       src/utils/cleanup.c \
       src/utils/failed_thread_cleanup.c \
       src/utils/logger.c \
       src/utils/time_utils.c


OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
DEBUG = -g
HEADER = -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(FLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 3 800 200 200 200 2 50 fifo

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
