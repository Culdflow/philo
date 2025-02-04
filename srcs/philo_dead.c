/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:56:18 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 04:47:19 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_philo_dead(t_philo *philo)
{
	philo = philo_get_first(philo);
	while (philo)
	{
		pthread_mutex_lock(philo->is_dead_mutex);
		philo->dead = 1;
		pthread_mutex_unlock(philo->is_dead_mutex);
		philo = philo->next;
	}
}

void	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead_mutex);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(philo->is_dead_mutex);
		exit(0);
	}
	pthread_mutex_unlock(philo->is_dead_mutex);
}

void	*philo_check_if_ate_enough(void *args)
{
	t_philo *philo = (t_philo *)args;
	t_philo	*philo_og = philo_get_first(philo);

	while (1)
	{
		while (philo)
		{
			if (philo->times_ate < philo->time->nb_times_eat)
				break ;
			philo = philo->next;
		}
		if (!philo)
		{
			set_philo_dead(philo_og);
			exit(0);
		}
		philo = philo_og;
	}
}
