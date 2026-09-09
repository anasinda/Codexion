/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:39:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/09 00:33:53 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	 t_coder *coder;
     t_dongle *dongle;

     coder = (t_coder*)arg;
     dongle = &coder->sim->dongles[0];

     dongle_acquire(dongle, coder);
     printf("%ld coder %d GOT D0\n", get_elapsed_time(coder->sim), coder->id);
     usleep(10 * 10000);
     dongle_release(coder->sim->config, dongle, get_elapsed_time(coder->sim));
     return (NULL);
}
