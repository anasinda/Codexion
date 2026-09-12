/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:39:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/12 05:43:20 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	t_coder	*coder;
    int	req_compile;

	coder = (t_coder *)arg;
	req_compile = coder->sim->config->number_of_compiles_required;
	while (coder->compile_count < req_compile)
	{
		if (acquire_pair(coder) != 0)
			break ;

		coder->last_compile_start = get_elapsed_time(coder->sim);
		log_state(coder, "is compiling");

		usleep(coder->sim->config->time_to_compile * 1000);

		coder->compile_count++;

		release_pair(coder);

		log_state(coder, "is debugging");
		usleep(coder->sim->config->time_to_debug * 1000);

		log_state(coder, "is refactoring");
		usleep(coder->sim->config->time_to_refactor * 1000);
	}
	return (NULL);
}
