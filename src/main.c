/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/06 18:23:31 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	main(int argc, char **argv)
{
	(void)argc;
	t_codexion_config config;

	if (parse_args(argc, argv, &config) == -1)
	{
		fprintf(stderr, "Error detected - PARSING FAILED...\n");
		return (1);
	}
	
	t_sim simulator;
	t_dongle * allocated_dongles;
	allocated_dongles = allocate_dongles(&config);
	if (!allocate_dongles)
	{
		fprintf(stderr, "Error detected - DONGLES FAILED TO ALLOCATE...\n");
		return (1);
	} 
	dongle_init(allocated_dongles, config.number_of_coders);
	if (simulator_init(&simulator, allocated_dongles, &config) == -1)
	{
		fprintf(stderr, "Error detected - FAILED TO INIT SIMULATOR...");
		return (1);
	}
	
	
	return (0);
}
