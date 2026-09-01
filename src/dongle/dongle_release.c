/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 03:55:16 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/01 04:01:43 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	dongle_release(t_codexion_config *config, t_dongle *dongle, long now)
{
	dongle->available = 1;
	dongle->available_after = now + config->dongle_cooldown;
}