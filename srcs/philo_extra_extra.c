/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_extra_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:54:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 05:15:45 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_hand->mutex);
		mutex_print("has taken a fork\n", philo);
		pthread_mutex_lock(&philo->left_hand->mutex);
		mutex_print("has taken a fork\n", philo);
	}
	else
	{
		pthread_mutex_lock(&philo->left_hand->mutex);
		mutex_print("has taken a fork\n", philo);
		pthread_mutex_lock(&philo->right_hand->mutex);
		mutex_print("has taken a fork\n", philo);
	}
	mutex_print("is eating\n", philo);
	pthread_mutex_lock(philo->set_eating_mutex);
	philo->time->time_last_ate = get_time();
	pthread_mutex_unlock(philo->set_eating_mutex);
	pthread_mutex_lock(philo->is_eating_mutex);
	philo->times_ate++;
	pthread_mutex_unlock(philo->is_eating_mutex);
	my_usleep(philo->time->time_to_eat, philo);
	pthread_mutex_unlock(&philo->right_hand->mutex);
	pthread_mutex_unlock(&philo->left_hand->mutex);
}

void	*philo_check_if_dead(void *args)
{
	t_philo *philo = (t_philo *)args;
	t_philo	*philo_og = philo_get_first(philo);

	while (1)
	{
		while (philo)
		{
			pthread_mutex_lock(philo->set_eating_mutex);
			if ((get_time() - philo->time->time_last_ate) >= philo->time->time_to_die)
			{
				pthread_mutex_unlock(philo->set_eating_mutex);
				philo_die(philo);
				set_philo_dead(philo);
				exit(0);
			}
			pthread_mutex_unlock(philo->set_eating_mutex);
			philo = philo->next;
		}
		philo = philo_og;
	}
}

void	philo_die(t_philo *philo)
{
	mutex_print("has died of hunger\n", philo);
}

void	mutex_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %d %s", get_time() - philo->time->time_project_start, philo->index, str);
	pthread_mutex_unlock(philo->print_mutex);
}

void	*philo_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		philo_eat(philo);
		philo_sleeping(philo);
	}
}
