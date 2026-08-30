/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/08/30 05:32:46 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>
#include <stdlib.h>


int	main(int argc, char **argv)
{
	(void)argc;
	t_codexion_config config;

	if (!parse_args(argc, argv, &config))
	{
		fprintf(stderr, "Error detected - PARSING FAILED...\n");
		return (1);
	}
	return (0);
}
