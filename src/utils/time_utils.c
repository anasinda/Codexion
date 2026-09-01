/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:50:45 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/01 03:20:23 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	get_current_time_ms(void)
{
	struct timespec ts;
	long	ms;
	
	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
	{
		fprintf(stderr, "Error detected - 'clock_gettime' function failed...\n");
		return (-1);
	}
	
	ms = (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
	return (ms);
}

long	get_elapsed_time(t_sim *sim)
{
	long	current_time;
	long	elasped_time;
	
	current_time = get_current_time_ms();
	if (current_time == -1)
		return (-1);
	
	elasped_time = current_time - sim->start_time;
	return (elasped_time);
}