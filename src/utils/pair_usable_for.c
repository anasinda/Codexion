/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_usable_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:17:23 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:17:34 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	pair_usable_for(t_coder *coder)
{
	if (!dongle_usable_for(coder->left_dongle, coder))
		return (0);
	if (!dongle_usable_for(coder->right_dongle, coder))
		return (0);
	return (1);
}