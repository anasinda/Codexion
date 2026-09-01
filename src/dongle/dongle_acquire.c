/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 04:08:05 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/01 04:28:41 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_acquire(t_dongle	*dongle, long now)
{
	if (dongle->available && (now >= dongle->available_after))
	{
		dongle->available = 0;
		return (0);
	}
	return (-1);
}