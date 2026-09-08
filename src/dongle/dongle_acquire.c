/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 04:08:05 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/09 00:08:26 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_acquire(t_dongle	*dongle, t_coder *coder)
{
	long	arrival_time;
	long	sequence;
    long	now;

	pthread_mutex_lock(&dongle->dongle_mutex);
	arrival_time = get_elapsed_time(coder->sim);
	sequence = dongle->next_sequence;
	dongle->next_sequence++;

	if (heap_push(&dongle->heap, arrival_time, sequence, coder) != 0)
		return (pthread_mutex_unlock(&dongle->dongle_mutex), -1);

	now = get_elapsed_time(coder->sim);
	while (!(dongle->available && now >= dongle->available_after && heap_peek(&dongle->heap) == coder))
    {
		pthread_cond_wait(&dongle->dongle_cond, &dongle->dongle_mutex);
		now = get_elapsed_time(coder->sim);
    }

    heap_pop(&dongle->heap);
    dongle->available = 0;

	return (pthread_mutex_unlock(&dongle->dongle_mutex), 0);
}
