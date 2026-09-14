/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 05:52:05 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 06:14:03 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_init_failed(t_main_vars main_vars)
{
	fprintf(stderr, "FAILED TO INIT DONGLES...\n");
    free(main_vars.allocated_dongles);
    return (1);
}

int	sim_init_failed(t_main_vars main_vars)
{
	fprintf(stderr, "Error detected - FAILED TO INIT SIMULATOR...\n");
	destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
	free(main_vars.allocated_dongles);
	return (1);
}

int coder_allocate_failed(t_main_vars main_vars)
{
	fprintf(stderr, "Error detected - CODERS FAILED TO ALLOCATE...\n");
    pthread_mutex_destroy(&main_vars.simulator.log_lock);
    pthread_mutex_destroy(&main_vars.simulator.state_lock);
    destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
    free(main_vars.allocated_dongles);
	return (1);
}

int coder_init_failed(t_main_vars main_vars)
{
	fprintf(stderr, "Error detected - Mutex init failed...\n");
	pthread_mutex_destroy(&main_vars.simulator.log_lock);
    pthread_mutex_destroy(&main_vars.simulator.state_lock);
    destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
	free(main_vars.allocated_dongles);
	free(main_vars.allocated_coders);
	return (1);
}

int	clock_gettime_failed(t_main_vars main_vars)
{
    free(main_vars.allocated_coders);
    pthread_mutex_destroy(&main_vars.simulator.log_lock);
    pthread_mutex_destroy(&main_vars.simulator.state_lock);
    destroy_initialized_dongles(main_vars.allocated_dongles, main_vars.config.number_of_coders);
    free(main_vars.allocated_dongles);
	return (1);
}