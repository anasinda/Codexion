/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 04:21:37 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 04:28:39 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int heap_remove(t_heap *heap, int coder_id)
{
    int index;
    
    index = heap_find(heap, coder_id);
    if (index == -1)
        return (-1);
    if (index == 0 && heap->size == 2)
        heap->entries[0] = heap->entries[1];
    heap->size--;
    return (0);
}