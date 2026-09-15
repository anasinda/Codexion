/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queuing_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:08:50 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 07:13:17 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	build_request(t_heap_entry *entry, t_coder *coder)
{
	long	last_compile_start;

	entry->blocked = 0;
	entry->coder = coder;
	entry->arrival = get_elapsed_time(coder->sim);
	pthread_mutex_lock(&coder->state_lock);
	last_compile_start = coder->last_compile_start;
	pthread_mutex_unlock(&coder->state_lock);
	entry->deadline = last_compile_start
		+ coder->sim->config->time_to_burnout;
}

int	queue_request_pair(t_coder *coder, t_heap_entry *request)
{
	t_scheduler_type	scheduler;

	scheduler = coder->sim->config->scheduler;

	if (ensure_queued(coder->left_dongle, request, scheduler) != 0)
		return (-1);

	if (ensure_queued(coder->right_dongle, request, scheduler) != 0)
		return (-1);

	return (0);
}