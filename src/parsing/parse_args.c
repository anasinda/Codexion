/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 03:38:09 by anasinda          #+#    #+#             */
/*   Updated: 2026/08/30 03:42:12 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	parse_args(int argc, char **argv, t_codexion_config *config)
{
	int i;
	
	if (argc != 9)
		return (0);
	
	i = 1;
	while (i <= argc)
	{
		if (i == argc)
		{
			
		}
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
}