/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 03:38:09 by anasinda          #+#    #+#             */
/*   Updated: 2026/08/30 22:38:49 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <string.h>

int	parse_args(int argc, char **argv, t_codexion_config *config)
{
	int i;

	if (argc != 9)
		return (0);

	i = 1;
	while (i <= 7)
	{
		if (!is_valid_number(argv[i]))
			return (0);

		if ((ft_atol(argv[i]) == 0 && i == 1) || (ft_atol(argv[i]) == 0 && i == 6))
			return (0);

		i++;
	}

	if (strcmp(argv[i], "fifo") == 0)
		config->scheduler = FIFO;
	else if (strcmp(argv[i], "edf") == 0)
		config->scheduler = EDF;
	else
		return (0);

	config->number_of_coders = ft_atol(argv[1]);
	config->time_to_burnout = ft_atol(argv[2]);
	config->time_to_compile = ft_atol(argv[3]);
	config->time_to_debug = ft_atol(argv[4]);
	config->time_to_refactor = ft_atol(argv[5]);
	config->number_of_compiles_required = ft_atol(argv[6]);
	config->dongle_cooldown = ft_atol(argv[7]);

	return (1);
}
