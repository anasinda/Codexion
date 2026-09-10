/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:37:45 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:37:55 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	lock_pair(t_coder *coder, t_dongle **first, t_dongle **second)
{
	order_dongles(coder, first, second);
	pthread_mutex_lock(&(*first)->dongle_mutex);
	pthread_mutex_lock(&(*second)->dongle_mutex);
}