/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_usable_for.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:15:13 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:15:36 by anasinda         ###   ########.fr       */
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

    if (dongle->heap.entries[0].coder != coder)
        return (0);

    return (1);
}