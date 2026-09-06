/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 04:08:05 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/06 02:41:57 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_acquire(t_dongle	*dongle, long now)
{
	pthread_mutex_lock(&dongle->dongle_mutex);
	while (!(dongle->available && now >= dongle->available_after))
	{
		pthread_cond_wait(&dongle->dongle_cond, &dongle->dongle_mutex);
		now = get_current_time_ms();
	}
	dongle->available = 0;
	pthread_mutex_unlock(&dongle->dongle_mutex);
	return (0);
	// if (dongle->available && (now >= dongle->available_after))
	// {
	// 	dongle->available = 0;
	// 	pthread_mutex_unlock(&dongle->dongle_mutex);
	// 	return (0);
	// }
}