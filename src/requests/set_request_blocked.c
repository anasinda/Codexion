/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_request_blocked.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:23:58 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 15:24:11 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	set_request_blocked(t_dongle *dongle, int coder_id, int value)
{
	int	index;

	index = heap_find(&dongle->heap, coder_id);
	if (index == -1)
		return (-1);
	dongle->heap.entries[index].blocked = value;
	return (0);
}
