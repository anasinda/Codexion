/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_should_stop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:23:25 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/13 23:23:33 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	simulation_should_stop(t_sim *sim)
{
	int	stop;

	pthread_mutex_lock(&sim->state_lock);
	stop = sim->stop;
	pthread_mutex_unlock(&sim->state_lock);
	return (stop);
}
