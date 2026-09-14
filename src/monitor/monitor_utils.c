/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_burned_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:36:56 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 05:15:35 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	all_coders_finished(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->config->number_of_coders)
	{
		if (sim->coders[i].compile_count
			< sim->config->number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}

int	coder_burned_out(t_coder *coder)
{
	long	now;
	long	deadline;

	now = get_elapsed_time(coder->sim);
	deadline = coder->last_compile_start
		+ coder->sim->config->time_to_burnout;

	return (now >= deadline);
}
