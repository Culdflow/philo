/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:39:41 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 04:10:05 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_time	*set_argv_time(char **argv)
{
	t_time	*result;

	result = malloc(sizeof(t_time));
	result->time_to_die = ft_atoi(argv[2]);
	result->time_to_eat = ft_atoi(argv[3]);
	result->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		result->nb_times_eat = ft_atoi(argv[5]);
	else
		result->nb_times_eat = 0;
	result->time_last_ate = get_time();
	result->time_project_start = get_time();
	return (result);
}

t_philo	*philo_new(t_philo *prev, t_philo *next, int index, char **argv)
{
	t_philo	*result;

	result = malloc(sizeof(t_philo));
	result->next = next;
	result->prev = prev;
	result->index = index;
	result->dead = 0;
	result->times_ate = 0;
	result->time = set_argv_time(argv);
	return (result);
}

t_philo	*philo_get_first(t_philo *philo)
{
	while (philo->prev)
		philo = philo->prev;
	return (philo);
}

void	philo_set_fork(t_philo *start, t_fork *forks)
{
	t_philo	*philo_start;

	philo_start = philo_get_first(start);
	while (philo_start)
	{
		philo_start->left_hand = fork_getfrom_index(forks, philo_start->index);
		philo_start->right_hand = fork_getfrom_index(forks, philo_start->index + 1);
		if (!philo_start->right_hand)
			philo_start->right_hand = fork_getfrom_index(forks, 0);
		philo_start = philo_start->next;
	}
}
