/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:39:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/04 20:22:30 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	 t_coder *coder;

     coder = (t_coder*)arg;
     log_state(coder, "has started");
     log_state(coder, "has finished");
     return (NULL);
}
