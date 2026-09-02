#ifndef CODEXION_H
# define CODEXION_H

#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum e_scheduler_type
{
    FIFO,
    EDF
} t_scheduler_type;

typedef struct s_codexion_config
{
	int	number_of_coders;
	int	time_to_burnout;
	int	time_to_compile;
	int	time_to_debug;
	int	time_to_refactor;
	int	number_of_compiles_required;
	long	dongle_cooldown;
	t_scheduler_type	scheduler;
} t_codexion_config;

typedef struct s_dongle
{
    pthread_mutex_t	dongle_mutex;
    pthread_cond_t	dongle_cond;
    int	available;
    long	available_after;
} t_dongle;

typedef struct s_sim
{
	t_codexion_config	config;
	t_dongle	*dongles;
	pthread_mutex_t	log_lock;
	long	start_time;
}	t_sim;
typedef struct s_coder
{
	int	id;
	pthread_t	thread;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	long	last_compile_start;
	int	compile_count;
	t_sim	*sim;
}	t_coder;

typedef struct s_heap_entry
{
	long	key;
	t_coder	*coder;
} t_heap_entry;

typedef	struct s_heap
{
	t_heap_entry	*entries;
	int	capacity;
	int	size;
}	t_heap;


int	is_valid_number(char *num_check);
long long ft_atol(char *str);
int	parse_args(int argc, char **argv, t_codexion_config *config);

#endif
