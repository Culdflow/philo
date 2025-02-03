/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:53:57 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 00:11:26 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_set_mutex(t_philo *philo, pthread_mutex_t *mutex)
{
	t_philo	*start;

	start = philo_get_first(philo);
	while (start)
	{
		start->print_mutex = mutex;
		start = start->next;
	}
}

t_philo	*philo_make_lst(int	philo_nb, char **argv, t_fork *forks, pthread_mutex_t *mutex)
{
	int		i;
	t_philo	*result;
	t_philo	*og;

	i = 0;
	result = philo_new(NULL, NULL, 0, argv);
	og = result;
	while (++i < philo_nb)
	{
		result->next = philo_new(result, NULL, i, argv);
		result = result->next;
	}
	philo_set_fork(og, forks);
	philo_set_mutex(og, mutex);
	return (og);
}

t_philo	*philo_getfrom_index(t_philo *start, int index)
{
	t_philo	*philo_start;

	philo_start = philo_get_first(start);
	while (philo_start)
	{
		if (philo_start->index == index)
			return (philo_start);
		philo_start = philo_start->next;
	}
	return (NULL);
}

void	philo_free(t_philo	*start)
{
	t_philo	*next;

	start = philo_get_first(start);
	while (start)
	{
		next = start->next;
		free(start->time);
		free(start);
		start = next;
	}
}

void	philo_sleeping(t_philo *philo)
{
	mutex_print("is sleeping\n", philo);
	my_usleep(philo->time->time_to_sleep, philo);
	mutex_print("is thinking\n", philo);
}
