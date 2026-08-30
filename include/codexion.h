#ifndef CODEXION_H
# define CODEXION_H

int	is_valid_number(char *num_check);


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
	int	dongle_cooldown;
	t_scheduler_type	scheduler;
} t_codexion_config;

#endif
