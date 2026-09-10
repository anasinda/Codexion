/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_should_yield.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 06:07:46 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 06:07:58 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	request_should_yield(t_heap_entry *entry, t_sim *sim)
{
	long	waited;
	long	limit;

	if (!entry->blocked)
		return (0);
	waited = get_elapsed_time(sim) - entry->arrival;
	limit = sim->config->time_to_compile
		+ sim->config->dongle_cooldown;
	return (waited < limit);
}