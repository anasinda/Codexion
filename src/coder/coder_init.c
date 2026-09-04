/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:26:32 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/03 19:47:19 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void    coder_init(t_coder *coders, t_dongle *dongles, t_sim *sim, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        int find_left_dongle;
        
        find_left_dongle = (i - 1 + n) % n;
        coders[i].id = i;
        coders[i].left_dongle = &dongles[find_left_dongle];
        coders[i].right_dongle = &dongles[i];
        coders[i].last_compile_start = 0;
        coders[i].compile_count = 0;
        coders[i].sim = sim;
        i++;
    }
}