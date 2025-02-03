/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:56:18 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 00:31:23 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_philo_dead(t_philo *philo)
{
	philo = philo_get_first(philo);
	while (philo)
	{
		philo->dead = 1;
		philo = philo->next;
	}
}

void	check_if_dead(t_philo *philo)
{
	if (philo->dead == 1)
		exit(0);
}