/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:36:56 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 07:09:15 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	all_coders_finished(t_sim *sim)
{
	int	i;
	int compile_count;
	

	i = 0;
	while (i < sim->config->number_of_coders)
	{

		pthread_mutex_lock(&sim->coders[i].state_lock);
		compile_count = sim->coders[i].compile_count;
		pthread_mutex_unlock(&sim->coders[i].state_lock);
		if (compile_count < sim->config->number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}

int	coder_burned_out(t_coder *coder)
{
	long	now;
	long	deadline;
	long	last_compile_start;

	now = get_elapsed_time(coder->sim);
	
	pthread_mutex_lock(&coder->state_lock);
	last_compile_start = coder->last_compile_start;
	pthread_mutex_unlock(&coder->state_lock);
	
	deadline = last_compile_start
		+ coder->sim->config->time_to_burnout;

	return (now >= deadline);
}
