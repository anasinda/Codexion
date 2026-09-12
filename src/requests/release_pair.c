/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 05:17:13 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/12 05:20:06 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	release_pair(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;
	long		now;

	lock_pair(coder, &first, &second);

	now = get_elapsed_time(coder->sim);

	coder->left_dongle->available = 1;
	coder->left_dongle->available_after =
		now + coder->sim->config->dongle_cooldown;

	coder->right_dongle->available = 1;
	coder->right_dongle->available_after =
		now + coder->sim->config->dongle_cooldown;

	unlock_pair(first, second);
}
