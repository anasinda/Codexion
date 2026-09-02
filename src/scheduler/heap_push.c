/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:05:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/02 03:37:31 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	heap_push(t_heap *heap, long key, t_coder *coder)
{
	int	index;
	
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
		}else
			break;
	}
}