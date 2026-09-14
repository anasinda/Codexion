/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fail_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 06:47:01 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/14 07:12:35 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_fail_cases(int argc, char *args, t_main_vars *main_vars)
{
	if (parse_args(argc, args, &main_vars->config) == -1)
		return (fprintf(stderr, "Error detected - PARSING FAILED...\n"), (1));

	main_vars->allocated_dongles = allocate_dongles(&main_vars->config);
	if (!main_vars->allocated_dongles)
		return (fprintf(stderr, "Error detected - DONGLES FAILED TO ALLOCATE...\n"), (1));

	if (dongle_init(main_vars->allocated_dongles, main_vars->config.number_of_coders) == -1)
		return dongle_init_failed(*main_vars);
		
	if (simulator_init(&main_vars->simulator, main_vars->allocated_dongles, &main_vars->config) == -1)
		return sim_init_failed(*main_vars);

	main_vars->allocated_coders = allocate_coders(&main_vars->config);
	if (!main_vars->allocated_coders)
		return (coder_allocate_failed(*main_vars));

	if (coder_init(main_vars->allocated_coders, main_vars->allocated_dongles, &main_vars->simulator, main_vars->config.number_of_coders) == -1)
		return (coder_init_failed(*main_vars));
	
    main_vars->simulator.coders = main_vars->allocated_coders;
	main_vars->simulator.start_time = get_current_time_ms();
    if (main_vars->simulator.start_time == -1)
		return (clock_gettime_failed(*main_vars));
	return (0);
}