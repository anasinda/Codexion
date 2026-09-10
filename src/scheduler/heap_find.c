/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 04:19:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 04:21:24 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_find(t_heap *heap, int coder_id)
{
    if (!heap || !heap->entries)
        return (-1);
    if (heap->size > 0 && heap->entries[0].coder->id == coder_id)
        return (0);
    if (heap->size > 1 && heap->entries[1].coder->id == coder_id)
        return (1);
    return (-1);
}