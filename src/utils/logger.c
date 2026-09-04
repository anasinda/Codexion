/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:08:55 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/04 15:16:30 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


void	log_state(t_coder *coder, char *message)
{
	long	elapsed_time;

	elapsed_time = get_elapsed_time(coder->sim);
    pthread_mutex_lock(&coder->sim->log_lock);
    printf("%ld %d %s\n", elapsed_time, coder->id, message);
    pthread_mutex_unlock(&coder->sim->log_lock);
}
