/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/07 17:53:16 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	main(int argc, char **argv)
{
	(void)argc;
	t_codexion_config config;
	t_sim simulator;
	t_dongle *allocated_dongles;
	t_coder *allocated_coders;
	int	coder_thread_count;
	int	join_thread_count;

	if (parse_args(argc, argv, &config) == -1)
	{
		fprintf(stderr, "Error detected - PARSING FAILED...\n");
		return (1);
	}

	allocated_dongles = allocate_dongles(&config);

	if (!allocated_dongles)
	{
		fprintf(stderr, "Error detected - DONGLES FAILED TO ALLOCATE...\n");
		return (1);
	}

	if (dongle_init(allocated_dongles, config.number_of_coders) == -1)
    {
        fprintf(stderr, "FAILED TO INIT DONGLES...\n");
        free(allocated_dongles);
        return (1);
    }

	if (simulator_init(&simulator, allocated_dongles, &config) == -1)
	{
		fprintf(stderr, "Error detected - FAILED TO INIT SIMULATOR...\n");
        destroy_initialized_dongles(allocated_dongles, config.number_of_coders);
        free(allocated_dongles);
		return (1);
	}

	allocated_coders = allocate_coders(&config);

	if (!allocated_coders)
	{
		fprintf(stderr, "Error detected - CODERS FAILED TO ALLOCATE...\n");
        pthread_mutex_destroy(&simulator.log_lock);
        destroy_initialized_dongles(allocated_dongles, config.number_of_coders);
        free(allocated_dongles);
		return (1);
	}

	coder_init(allocated_coders, allocated_dongles, &simulator, config.number_of_coders);
	simulator.start_time = get_current_time_ms();
    if (simulator.start_time == -1)
    {
        free(allocated_coders);
        pthread_mutex_destroy(&simulator.log_lock);
        destroy_initialized_dongles(allocated_dongles, config.number_of_coders);
        free(allocated_dongles);
        return (1);
    }

	coder_thread_count = 0;

	while (coder_thread_count < config.number_of_coders)
	{
		if (pthread_create(&allocated_coders[coder_thread_count].thread, NULL, coder_routine, &allocated_coders[coder_thread_count]) != 0)
            break;
        coder_thread_count++;
	}

	join_thread_count = 0;

	while (join_thread_count < coder_thread_count)
	{
		pthread_join(allocated_coders[join_thread_count].thread, NULL);
		join_thread_count++;
	}

    free(allocated_coders);
    pthread_mutex_destroy(&simulator.log_lock);
    destroy_initialized_dongles(allocated_dongles, config.number_of_coders);
    free(allocated_dongles);
	return (0);
}
