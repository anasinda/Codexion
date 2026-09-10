/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:38:15 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:38:24 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	unlock_pair(t_dongle *first, t_dongle *second)
{
	pthread_mutex_unlock(&second->dongle_mutex);
	pthread_mutex_unlock(&first->dongle_mutex);
}