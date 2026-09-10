#ifndef CODEXION_H
# define CODEXION_H

#define _DEFAULT_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

typedef struct s_sim t_sim;
typedef struct s_coder t_coder;
typedef struct s_dongle t_dongle;

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



typedef struct s_heap_entry
{
	t_coder *coder;
	long arrival;
	long deadline;
} t_heap_entry;

typedef	struct s_heap
{
	t_heap_entry	*entries;
	int	capacity;
	int	size;
}	t_heap;

typedef struct s_sim
{
	t_codexion_config	*config;
	t_dongle	*dongles;
	pthread_mutex_t	log_lock;
	long	start_time;
}	t_sim;

typedef struct s_dongle
{
	pthread_mutex_t	dongle_mutex;
	pthread_cond_t	dongle_cond;
	int	id;
	int	available;
	long	available_after;
	long	next_sequence;
	t_heap	heap;

} t_dongle;

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

long	get_current_time_ms(void);
long	get_elapsed_time(t_sim *sim);
int	is_valid_number(char *num_check);
long long ft_atol(char *str);
int	parse_args(int argc, char **argv, t_codexion_config *config);
void	log_state(t_coder *coder, char *message);
int	heap_init(t_heap *heap, int capacity);
int	heap_push(t_heap *heap, t_heap_entry new_entry, t_scheduler_type scheduler);
int	check_children(t_heap *heap, int index, int pos_small);
int	dongle_init(t_dongle *dongles, int n);
int	dongle_acquire(t_dongle	*dongle, t_coder *coder);
void	dongle_release(t_codexion_config *config, t_dongle *dongle, long now);
void    coder_init(t_coder *coders, t_dongle *dongles, t_sim *sim, int n);
void	*coder_routine(void *arg);
t_dongle	*allocate_dongles(t_codexion_config *config);
t_coder *allocate_coders(t_codexion_config *config);
int simulator_init(t_sim *simulator, t_dongle *allocated_dongles, t_codexion_config *config);
void destroy_initialized_dongles(t_dongle *dongles, int count);
t_coder	*heap_peek(t_heap	*heap);
t_coder	*heap_pop(t_heap *heap);
void	order_dongles(t_coder *coder, t_dongle **first, t_dongle **second);
int	acquire_dongle_pair(t_coder *coder);
int	heap_find(t_heap *heap, int coder_id);
int	request_is_better(t_heap_entry *a, t_heap_entry *b, t_scheduler_type scheduler);
void    build_request(t_heap_entry *entry, t_coder *coder);
int ensure_queued(t_dongle *dongle, t_heap_entry *entry, t_scheduler_type scheduler);
int	queue_request_pair(t_coder *coder, t_heap_entry *request);

#endif
