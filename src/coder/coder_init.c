/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:26:32 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 03:44:58 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_initialized_coder_mutexes(t_coder *coders, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&coders[i].state_lock);
		i++;
	}
}

int	coder_init(t_coder *coders, t_dongle *dongles, t_sim *sim, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        int find_left_dongle;

        find_left_dongle = (i - 1 + n) % n;
        coders[i].id = i + 1;
        coders[i].left_dongle = &dongles[find_left_dongle];
        coders[i].right_dongle = &dongles[i];
        coders[i].last_compile_start = 0;
        coders[i].compile_count = 0;
        coders[i].sim = sim;
        if (pthread_mutex_init(&coders[i].state_lock, NULL) != 0)
		{
			destroy_initialized_coder_mutexes(coders, i);
            return (-1);
		}
        i++;
    }
	return (0);
}
