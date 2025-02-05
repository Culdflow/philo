/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:56:18 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/05 18:44:10 by dfeve            ###   ########.fr       */
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
	t_philo	*philo;
	t_philo	*philo_og;

	philo = (t_philo *)args;
	philo_og = philo_get_first(philo);
	while (1)
	{
		while (philo)
		{
			pthread_mutex_lock(philo->is_eating_mutex);
			if (philo->times_ate < philo->time->nb_times_eat)
			{
				pthread_mutex_unlock(philo->is_eating_mutex);
				break ;
			}
			pthread_mutex_unlock(philo->is_eating_mutex);
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

void	set_all_struct(t_all **all_struct, char **argv)
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	is_eating_mutex;
	pthread_mutex_t	set_eating_mutex;

	pthread_mutex_init(&print_mutex, NULL);
	pthread_mutex_init(&is_dead_mutex, NULL);
	pthread_mutex_init(&is_eating_mutex, NULL);
	pthread_mutex_init(&set_eating_mutex, NULL);
	(*all_struct) = malloc(sizeof(t_all));
	(*all_struct)->i = -1;
	(*all_struct)->print_mutex = print_mutex;
	(*all_struct)->is_dead_mutex = is_dead_mutex;
	(*all_struct)->is_eating_mutex = is_eating_mutex;
	(*all_struct)->set_eating_mutex = set_eating_mutex;
	(*all_struct)->forks = fork_make_lst(ft_atoi(argv[1]));
	(*all_struct)->philo = philo_make_lst(ft_atoi(argv[1]), argv, *all_struct);
}
