/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:56:01 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/06 17:56:25 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*allocate_dongles(t_codexion_config *config)
{
	t_dongle *dongles;

	dongles = malloc(sizeof(t_dongle) * config->number_of_coders);
	if (!dongles)
		return NULL;

	return dongles;
}
