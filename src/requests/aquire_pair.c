/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aquire_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 05:15:21 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/13 23:26:37 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	acquire_pair(t_coder *coder)
{
	t_heap_entry	request;
	int				result;

	build_request(&request, coder);

	while (!simulation_should_stop(coder->sim))
	{
		result = try_pair_once(coder, &request);
		if (result == 1)
			return (0);
		if (result == -1)
			return (-1);
		usleep(1000);
	}
    return (-1);
}
