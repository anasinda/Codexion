/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 05:15:21 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 05:39:59 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	unlock_pair(t_dongle *first, t_dongle *second)
{
	pthread_mutex_unlock(&second->dongle_mutex);
	pthread_mutex_unlock(&first->dongle_mutex);
}

void	lock_pair(t_coder *coder, t_dongle **first, t_dongle **second)
{
	order_dongles(coder, first, second);
	pthread_mutex_lock(&(*first)->dongle_mutex);
	pthread_mutex_lock(&(*second)->dongle_mutex);
}

void	release_pair(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;
	long		now;

	lock_pair(coder, &first, &second);

	now = get_elapsed_time(coder->sim);

	coder->left_dongle->available = 1;
	coder->left_dongle->available_after =
		now + coder->sim->config->dongle_cooldown;

	coder->right_dongle->available = 1;
	coder->right_dongle->available_after =
		now + coder->sim->config->dongle_cooldown;

	unlock_pair(first, second);
}


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

int	acquire_pair(t_coder *coder)
{
	t_heap_entry	request;
	int				result;

	build_request(&request, coder);

	while (!simulation_should_stop(coder->sim))
	{
		result = try_pair_once(coder, &request);
		if (result == 1)
			return (0);
		if (result == -1)
			return (-1);
		usleep(1000);
	}
	return (-1);
}