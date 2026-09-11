/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_has_priority.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:51:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/11 12:54:35 by anasinda         ###   ########.fr       */
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