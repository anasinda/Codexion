/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_usable_for.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:15:13 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/11 12:58:00 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_usable_for(t_dongle *dongle, t_coder *coder)
{
    if (!dongle->available)
	return (0);

    if (get_elapsed_time(coder->sim) < dongle->available_after)
        return (0);

    if (heap_find(&dongle->heap, coder->id) == -1)
        return (0);

    if (!request_has_priority(dongle, coder))
        return (0);

    return (1);
}