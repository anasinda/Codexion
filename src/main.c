/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:49:31 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/01 04:31:29 by anasinda         ###   ########.fr       */
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
	return (0);
}
