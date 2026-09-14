/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:15:13 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 05:15:11 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void    order_dongles(t_coder *coder, t_dongle **first, t_dongle **second)
{
    if (coder->left_dongle->id < coder->right_dongle->id)
    {
        *first = coder->left_dongle;
        *second = coder->right_dongle;
    }
    else
    {
        *first = coder->right_dongle;
		*second = coder->left_dongle;
    }
}

void	dongle_release(t_codexion_config *config, t_dongle *dongle, long now)
{
    pthread_mutex_lock(&dongle->dongle_mutex);
	dongle->available = 1;
	dongle->available_after = now + config->dongle_cooldown;
    pthread_cond_broadcast(&dongle->dongle_cond);
    pthread_mutex_unlock(&dongle->dongle_mutex);
}

int	dongle_usable_for(t_dongle *dongle, t_coder *coder)
{
    if (!dongle->available)
	return (0);

    if (get_elapsed_time(coder->sim) < dongle->available_after)
        return (0);

    if (heap_find(&dongle->heap, coder->id) == -1)
        return (0);

    if (!request_has_priority(dongle, coder))
        return (0);

    return (1);
}