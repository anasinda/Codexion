/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_request_pair.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:08:50 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:08:58 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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