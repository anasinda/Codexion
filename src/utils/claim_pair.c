/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claim_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:20:09 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/10 05:20:17 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	claim_pair(t_coder *coder)
{
	if (heap_remove(&coder->left_dongle->heap, coder->id) != 0)
		return (-1);
	if (heap_remove(&coder->right_dongle->heap, coder->id) != 0)
		return (-1);
	coder->left_dongle->available = 0;
	coder->right_dongle->available = 0;
	return (0);
}