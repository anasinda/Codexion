/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_queued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 04:33:44 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 04:53:36 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int ensure_queued(t_dongle *dongle, t_heap_entry *entry, t_scheduler_type scheduler)
{
    if (heap_find(&dongle->heap, entry->coder->id) != -1)
        return (0);
    return (heap_push(&dongle->heap, *entry, scheduler));
}