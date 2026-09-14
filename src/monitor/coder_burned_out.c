/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_burned_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:36:56 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/13 23:38:07 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	coder_burned_out(t_coder *coder)
{
	long	now;
	long	deadline;

	now = get_elapsed_time(coder->sim);
	deadline = coder->last_compile_start
		+ coder->sim->config->time_to_burnout;

	return (now >= deadline);
}
