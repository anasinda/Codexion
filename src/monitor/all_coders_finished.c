/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_coders_finished.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:48:15 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 02:53:34 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	all_coders_finished(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->config->number_of_coders)
	{
		if (sim->coders[i].compile_count
			< sim->config->number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}
