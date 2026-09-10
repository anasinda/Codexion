/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 04:08:05 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 01:23:37 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	check_key_type(t_coder * coder)
{
	long	choose_key;

	if (coder->sim->config->scheduler == FIFO)
		choose_key = get_elapsed_time(coder->sim);
	else
	{
		choose_key = coder->last_compile_start + coder->sim->config->time_to_burnout;
	}

	return choose_key;
}

int	dongle_acquire(t_dongle	*dongle, t_coder *coder)
{
	long	key;
	long	sequence;
    long	now;

	pthread_mutex_lock(&dongle->dongle_mutex);
	key = check_key_type(coder);
	sequence = dongle->next_sequence;
	dongle->next_sequence++;

	if (heap_push(&dongle->heap, key, sequence, coder) != 0)
		return (pthread_mutex_unlock(&dongle->dongle_mutex), -1);

	while (1)
	{
		now = get_elapsed_time(coder->sim);
		if (dongle->available
			&& now >= dongle->available_after
			&& heap_peek(&dongle->heap) == coder)
			break ;
		if (!dongle->available
			|| heap_peek(&dongle->heap) != coder)
		{
			pthread_cond_wait(&dongle->dongle_cond,
				&dongle->dongle_mutex);
		}
		else
		{
			pthread_mutex_unlock(&dongle->dongle_mutex);
			usleep(1000);
			pthread_mutex_lock(&dongle->dongle_mutex);
		}
	}

    heap_pop(&dongle->heap);
    dongle->available = 0;
	
	return (pthread_mutex_unlock(&dongle->dongle_mutex), 0);
}
