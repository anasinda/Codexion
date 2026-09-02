/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:50:00 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/02 05:20:26 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_children(t_heap *heap, int index, int pos_small)
{
	int	left;
	int	right;
	
	left = (2 * index) + 1;
	if (left < heap->size)
	{
		if (heap->entries[left].key < heap->entries[pos_small].key)
				pos_small = left;
	}
	
	right = (2 * index) + 2;
	if (right < heap->size)
	{
		if (heap->entries[right].key < heap->entries[pos_small].key)
				pos_small = right;
	}
	return (pos_small);
}

t_coder	*heap_pop(t_heap *heap)
{
	int	smallest;
	int	index;
	t_coder	*pop_smallest;

	pop_smallest = heap->entries[0].coder;
	heap->entries[0] = heap->entries[heap->size - 1];
	heap->entries[heap->size - 1].coder = NULL;
	heap->entries[heap->size - 1].key = -1;
	heap->size -= 1;

	index = 0;
	smallest = index;
	while (1)
	{
		t_heap_entry	temp_entry;
		
		smallest = check_children(heap, index, smallest);
		if (smallest != index)
		{
			temp_entry = heap->entries[index];
			heap->entries[index] = heap->entries[smallest];
			heap->entries[smallest] = temp_entry;
			index = smallest;
		}else
			break;
	}
	return pop_smallest;
}