/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:57:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/07 16:44:06 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int simulator_init(t_sim *simulator, t_dongle *allocated_dongles, t_codexion_config *config)
{
    int i;

    i = 0;
    simulator->config = config;
    simulator->dongles = allocated_dongles;
    simulator->start_time = 0;

    if (pthread_mutex_init(&simulator->log_lock, NULL) != 0)
    {
        return (-1);
    }
    return (0);
}
