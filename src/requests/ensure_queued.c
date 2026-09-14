/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_queued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 04:33:44 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 05:09:27 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	claim_pair(t_coder *coder)
{
	if (heap_remove(&coder->left_dongle->heap, coder->id) != 0)
		return (-1);
	if (heap_remove(&coder->right_dongle->heap, coder->id) != 0)
		return (-1);
	coder->left_dongle->available = 0;
	coder->right_dongle->available = 0;
	return (0);
}

int	pair_usable_for(t_coder *coder)
{
	if (!dongle_usable_for(coder->left_dongle, coder))
		return (0);
	if (!dongle_usable_for(coder->right_dongle, coder))
		return (0);
	return (1);
}

int ensure_queued(t_dongle *dongle, t_heap_entry *entry, t_scheduler_type scheduler)
{
    if (heap_find(&dongle->heap, entry->coder->id) != -1)
        return (0);
    return (heap_push(&dongle->heap, *entry, scheduler));
}