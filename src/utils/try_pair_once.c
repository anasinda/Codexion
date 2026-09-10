/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_pair_once.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 06:02:00 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 06:02:10 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	try_pair_once(t_coder *coder, t_heap_entry *request)
{
	t_dongle	*first;
	t_dongle	*second;
	int			result;

	lock_pair(coder, &first, &second);

	if (queue_request_pair(coder, request) != 0)
		result = -1;
	else if (pair_usable_for(coder))
	{
		if (claim_pair(coder) != 0)
			result = -1;
		else
			result = 1;
	}
	else
		result = 0;

	unlock_pair(first, second);
	return (result);
}