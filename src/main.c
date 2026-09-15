/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 05:01:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	finished_coders_cleanup(t_main_vars main_vars)
{
	destroy_initialized_coder_mutexes(main_vars.allocated_coders, main_vars.config.number_of_coders);
	free(main_vars.allocated_coders);
	pthread_mutex_destroy(&main_vars.simulator.log_lock);
	pthread_mutex_destroy(&main_vars.simulator.state_lock);
	destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
	free(main_vars.allocated_dongles);
}

int	thread_creating(t_main_vars *main_vars)
{
	main_vars->coder_thread_count = 0;
	while (main_vars->coder_thread_count < main_vars->config.number_of_coders)
	{
		if (pthread_create(&main_vars->allocated_coders[main_vars->coder_thread_count].thread,
			NULL, coder_routine, &main_vars->allocated_coders[main_vars->coder_thread_count]) != 0)
            return (-1);
        main_vars->coder_thread_count++;
	}
	return (0);
}

int	monitor_thread_create(t_main_vars *main_vars)
{
	if (pthread_create(&main_vars->monitor_thread, NULL,
			monitor_routine, &main_vars->simulator) != 0)
		return (-1);
	return (0);
}

void	thread_joining(t_main_vars *main_vars)
{
	main_vars->join_thread_count = 0;
	while (main_vars->join_thread_count < main_vars->coder_thread_count)
	{
		pthread_join(main_vars->allocated_coders[main_vars->join_thread_count].thread, NULL);
		main_vars->join_thread_count++;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_main_vars  main_vars;

	if (check_fail_cases(argc, argv, &main_vars) != 0)
	return (1);
	
	if (thread_creating(&main_vars) != 0 || monitor_thread_create(&main_vars) != 0)
		return (thread_creation_failed(&main_vars));

	thread_joining(&main_vars);
	
	pthread_join(main_vars.monitor_thread, NULL);
	
	finished_coders_cleanup(main_vars);
	return (0);
}
