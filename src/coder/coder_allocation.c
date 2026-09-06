/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:23:50 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/06 18:29:48 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder *allocate_coders(t_codexion_config *config)
{
    t_coder *coders;
    coders = malloc(sizeof(t_coder) * config->number_of_coders);
    
    if (!coders)
        return NULL;
    return coders;
}