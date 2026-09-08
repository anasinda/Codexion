/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:05:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/08 04:02:28 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_push(t_heap *heap, long key, t_coder *coder)
{
	int	index;

	if (!heap || !heap->entries || !coder)
		return -1;
	if (heap->size >= heap->capacity)
		return -1;
	
	heap->entries[heap->size].coder = coder;
	heap->entries[heap->size].key = key;
	heap->size += 1;
	
	index = heap->size - 1;
	while (index > 0)
	{
		int	parent;
		t_heap_entry temp_entry;

		parent = (index - 1) / 2;
		if (heap->entries[index].key < heap->entries[parent].key)
		{
			temp_entry = heap->entries[parent];
			heap->entries[parent] = heap->entries[index];
			heap->entries[index] = temp_entry;
			index = parent;
		}else if (heap->entries[index].key == heap->entries[parent].key)
		{
			if (heap->entries[index].sequence < heap->entries[parent].sequence)
			{
				temp_entry = heap->entries[parent];
				heap->entries[parent] = heap->entries[index];
				heap->entries[index] = temp_entry;
				index = parent;
			}
		}else
			break;
	}
	return (0);
}