/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_pair_once.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 06:02:00 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/11 01:02:30 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	try_pair_once(t_coder *coder, t_heap_entry *request)
{
	t_dongle	*first;
	t_dongle	*second;
    int	left_ok;
	int	right_ok;
	int	result;

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
	{
		left_ok = dongle_usable_for(coder->left_dongle, coder);
		right_ok = dongle_usable_for(coder->right_dongle, coder);

		set_request_blocked(coder->left_dongle, coder->id, !right_ok);
		set_request_blocked(coder->right_dongle, coder->id, !left_ok);

		result = 0;
	}


	unlock_pair(first, second);
	return (result);
}
