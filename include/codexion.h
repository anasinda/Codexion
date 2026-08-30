#ifndef CODEXION_H
# define CODEXION_H

#include <pthread.h>
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
    pthread_cond_t	dongle_wait;
    int	available;
    long	available_after;
} t_dongle;

int	is_valid_number(char *num_check);
long long ft_atol(char *str);
int	parse_args(int argc, char **argv, t_codexion_config *config);

#endif
