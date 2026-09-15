/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:23:58 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 20:05:07 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	request_has_priority(t_dongle *dongle, t_coder *coder)
{
	t_heap *heap;

	heap = &dongle->heap;
	if (heap->size == 0)
		return (0);
	if (heap->entries[0].coder == coder)
		return (1);
	if (heap->size == 2 && heap->entries[1].coder == coder && request_should_yield(&heap->entries[0], coder->sim))
		return (1);
	return (0);
}

int	request_is_better(t_heap_entry *a, t_heap_entry *b, t_scheduler_type scheduler)
{
	if (scheduler == FIFO)
	{
		if (a->arrival != b->arrival)
			return (a->arrival < b->arrival);
	}else
	{
		if (a->deadline != b->deadline)
			return (a->deadline < b->deadline);
	}
	return (a->coder->id < b->coder->id);
}

int	request_should_yield(t_heap_entry *entry, t_sim *sim)
{
	long	blocked_for;
	long	limit;

	if (!entry->blocked)
		return (0);
	blocked_for = get_elapsed_time(sim) - entry->blocked_since;
	limit = sim->config->time_to_compile
		+ sim->config->dongle_cooldown;
	return (blocked_for < limit);
}

int	set_request_blocked(t_dongle *dongle, int coder_id, int value)
{
	int				index;
	t_heap_entry	*entry;

	index = heap_find(&dongle->heap, coder_id);
	if (index == -1)
		return (-1);
	entry = &dongle->heap.entries[index];
	if (value && !entry->blocked)
		entry->blocked_since = get_elapsed_time(entry->coder->sim);
	else if (!value)
		entry->blocked_since = 0;
	entry->blocked = value;
	return (0);
}
