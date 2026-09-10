/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_is_better.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 03:48:08 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 03:55:52 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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