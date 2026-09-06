/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/06 18:49:15 by anasinda         ###   ########.fr       */
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

	dongle_init(allocated_dongles, config.number_of_coders);
	
	if (simulator_init(&simulator, allocated_dongles, &config) == -1)
	{
		fprintf(stderr, "Error detected - FAILED TO INIT SIMULATOR...\n");
		return (1);
	}
	
	allocated_coders = allocate_coders(&config);
	
	if (!allocated_coders)
	{
		fprintf(stderr, "Error detected - CODERS FAILED TO ALLOCATE...\n");
		return (1);
	}
	
	coder_init(allocated_coders, allocate_dongles, &simulator, config.number_of_coders);
	simulator.start_time = get_current_time_ms();
	
	coder_thread_count = 0;
	
	while (coder_thread_count < config.number_of_coders)
	{
		pthread_create(&allocated_coders[coder_thread_count].thread, NULL, coder_routine, &allocated_coders[coder_thread_count]);
		coder_thread_count++;
	}
	
	join_thread_count = 0;

	while (join_thread_count < config.number_of_coders)
	{
		pthread_join(allocated_coders[join_thread_count].thread, NULL);
		join_thread_count++;
	}
	
	return (0);
}
