/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 06:22:22 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_fail_cases(int argc, char *args, t_main_vars *main_vars)
{
	if (parse_args(argc, args, &main_vars->config) == -1)
		return (fprintf(stderr, "Error detected - PARSING FAILED...\n"), (1));

	main_vars->allocated_dongles = allocate_dongles(&main_vars->config);
	if (!main_vars->allocated_dongles)
		return (fprintf(stderr, "Error detected - DONGLES FAILED TO ALLOCATE...\n"), (1));

	if (dongle_init(main_vars->allocated_dongles, main_vars->config.number_of_coders) == -1)
		return dongle_init_failed(*main_vars);
		
	if (simulator_init(&main_vars->simulator, main_vars->allocated_dongles, &main_vars->config) == -1)
		return sim_init_failed(*main_vars);

	main_vars->allocated_coders = allocate_coders(&main_vars->config);
	if (!main_vars->allocated_coders)
		return (coder_allocate_failed(*main_vars));

	if (coder_init(main_vars->allocated_coders, main_vars->allocated_dongles, &main_vars->simulator, main_vars->config.number_of_coders) == -1)
		return (coder_init_failed(*main_vars));
	
	main_vars->simulator.start_time = get_current_time_ms();
    if (main_vars->simulator.start_time == -1)
		return (clock_gettime_failed(*main_vars));
}


int	main(int argc, char **argv)
{
	(void)argc;
	t_main_vars  main_vars;
	
	// if (parse_args(argc, argv, &main_vars.config) == -1)
	// 	return (fprintf(stderr, "Error detected - PARSING FAILED...\n"), (1));

	// main_vars.allocated_dongles = allocate_dongles(&main_vars.config);
	// if (!main_vars.allocated_dongles)
	// 	return (fprintf(stderr, "Error detected - DONGLES FAILED TO ALLOCATE...\n"), (1));

	// if (dongle_init(main_vars.allocated_dongles, main_vars.config.number_of_coders) == -1)
	// 	return dongle_init_failed(main_vars);
		
	// if (simulator_init(&main_vars.simulator, main_vars.allocated_dongles, &main_vars.config) == -1)
	// 	return sim_init_failed(main_vars);

	// main_vars.allocated_coders = allocate_coders(&main_vars.config);

	// if (!main_vars.allocated_coders)
	// 	return (coder_allocate_failed(main_vars));

	// if (coder_init(main_vars.allocated_coders, main_vars.allocated_dongles, &main_vars.simulator, main_vars.config.number_of_coders) == -1)
	// 	return (coder_init_failed(main_vars));
	
	// main_vars.simulator.start_time = get_current_time_ms();
    // if (main_vars.simulator.start_time == -1)
	// 	return (clock_gettime_failed(main_vars));

	main_vars.coder_thread_count = 0;
	while (main_vars.coder_thread_count < main_vars.config.number_of_coders)
	{
		if (pthread_create(&main_vars.allocated_coders[main_vars.coder_thread_count].thread,
			NULL, coder_routine, &main_vars.allocated_coders[main_vars.coder_thread_count]) != 0)
            break;
        main_vars.coder_thread_count++;
	}

	main_vars.join_thread_count = 0;
	while (main_vars.join_thread_count < main_vars.coder_thread_count)
	{
		pthread_join(main_vars.allocated_coders[main_vars.join_thread_count].thread, NULL);
		main_vars.join_thread_count++;
	}

    free(main_vars.allocated_coders);
    pthread_mutex_destroy(&main_vars.simulator.log_lock);
    pthread_mutex_destroy(&main_vars.simulator.state_lock);
    destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
    free(main_vars.allocated_dongles);
	return (0);
}
