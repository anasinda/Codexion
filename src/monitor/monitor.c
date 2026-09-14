/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:40:24 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/13 23:45:16 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*monitor_routine(void *arg)
{
	t_sim	*sim;
	int		i;

	sim = (t_sim *)arg;
	while (!simulation_should_stop(sim))
	{
		i = 0;
		while (i < sim->config->number_of_coders)
		{
			if (coder_burned_out(&sim->coders[i]))
			{
				log_state(&sim->coders[i], "burned out");
				stop_simulation(sim);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
