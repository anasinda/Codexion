/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:05:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 04:07:48 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_push(t_heap *heap, t_heap_entry new_entry,
		t_scheduler_type scheduler)
{
	if (!heap || !heap->entries)
		return (-1);
	if (heap->size >= heap->capacity)
		return (-1);
	if (heap->size == 0)
	{
		heap->entries[0] = new_entry;
		heap->size = 1;
		return (0);
	}
	if (request_is_better(&new_entry, &heap->entries[0], scheduler))
	{
		heap->entries[1] = heap->entries[0];
		heap->entries[0] = new_entry;
	}
	else
		heap->entries[1] = new_entry;
	heap->size = 2;
	return (0);
}