/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 02:16:51 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/08 03:59:43 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_initialized_dongles(t_dongle	*dongles, int count)
{
	while (count > 0)
	{
		count--;
		pthread_cond_destroy(&dongles[count].dongle_cond);
		pthread_mutex_destroy(&dongles[count].dongle_mutex);
        free(dongles[count].heap.entries);
	}
}

int	dongle_init(t_dongle *dongles, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&dongles[i].dongle_mutex, NULL) != 0)
		{
			fprintf(stderr, "Error detected - Mutex init failed...\n");
			destroy_initialized_dongles(dongles, i);
			return (-1);
		}

		if (pthread_cond_init(&dongles[i].dongle_cond, NULL) != 0)
		{
			fprintf(stderr, "Error detected - Cond init failed...\n");
			pthread_mutex_destroy(&dongles[i].dongle_mutex);
			destroy_initialized_dongles(dongles, i);
			return (-1);
		}

		if (heap_init(&dongles[i].heap, 2) != 0)
		{
			fprintf(stderr, "Error detected - Heap init failed...\n");
			pthread_cond_destroy(&dongles[i].dongle_cond);
    		pthread_mutex_destroy(&dongles[i].dongle_mutex);
			destroy_initialized_dongles(dongles, i);
			return (-1);
		}

		dongles[i].available = 1;
		dongles[i].available_after = 0;
		dongles[i].next_sequence = 0;
		i++;
	}
	return (0);
}
