/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_thread_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 04:47:22 by anasinda          #+#    #+#             */
/*   Updated: 2026/09/15 05:00:29 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	thread_creation_failed(t_main_vars *main_vars)
{
	stop_simulation(&main_vars->simulator);
	thread_joining(main_vars);
	finished_coders_cleanup(*main_vars);
	return (1);
}
