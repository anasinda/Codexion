/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 02:55:16 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/02 03:01:58 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_init(t_heap *heap, int capacity)
{
	heap->entries = malloc(sizeof(t_heap_entry) * capacity);
	if(!heap->entries)
		return (-1);
		
	heap->capacity = capacity;
	heap->size = 0;
	return (0);
}