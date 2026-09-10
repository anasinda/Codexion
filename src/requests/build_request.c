/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_request.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 04:30:43 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 04:32:26 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void    build_request(t_heap_entry *entry, t_coder *coder)
{
    entry->coder = coder;
    entry->arrival = get_elapsed_time(coder->sim);
    entry->deadline = coder->last_compile_start + coder->sim->config->time_to_burnout;
}