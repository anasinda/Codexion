/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:39:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 05:30:31 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	debug_refactor_task(t_coder *coder)
{
	log_state(coder, "is debugging");
	if (simulation_sleep(coder->sim, (coder->sim->config->time_to_debug * 1000) != 0))
		return (-1);

	log_state(coder, "is refactoring");
	if (simulation_sleep(coder->sim, (coder->sim->config->time_to_refactor * 1000) != 0))
		return (-1);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;
    int	req_compile;

	coder = (t_coder *)arg;
	req_compile = coder->sim->config->number_of_compiles_required;
	while ((coder->compile_count < req_compile) && !simulation_should_stop(coder->sim))
	{
		if (acquire_pair(coder) != 0)
			break ;

		pthread_mutex_lock(&coder->state_lock);
		coder->last_compile_start = get_elapsed_time(coder->sim);
		pthread_mutex_unlock(&coder->state_lock);

		log_state(coder, "is compiling");
		if (simulation_sleep(coder->sim, (coder->sim->config->time_to_compile * 1000) != 0))
			break;

		pthread_mutex_lock(&coder->state_lock);
		coder->compile_count++;
		pthread_mutex_unlock(&coder->state_lock);

		release_pair(coder);
		if (debug_refactor_task(coder) != 0)
			break;
	}
	return (NULL);
}
