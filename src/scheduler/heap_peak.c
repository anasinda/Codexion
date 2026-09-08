/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_peak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 03:38:23 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/08 04:09:20 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder	*heap_peek(t_heap	*heap)
{
	if (!heap || !heap->entries || heap->size == 0)
		return NULL;
	
	
	return heap->entries[0].coder;
}