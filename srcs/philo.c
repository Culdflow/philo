/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:39:41 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/03 01:10:48 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_time	*set_argv_time(char **argv)
{
	t_time	*result;
	struct timeval	*time_since_last_ate;

	time_since_last_ate = malloc(sizeof(struct timeval));
	gettimeofday(time_since_last_ate, NULL);
	result = malloc(sizeof(t_time));
	result->time_to_die = ft_atoi(argv[2]);
	result->time_to_eat = ft_atoi(argv[3]);
	result->time_to_sleep = ft_atoi(argv[4]);
	result->time_since_last_ate = time_since_last_ate;
	return (result);
}

t_philo	*philo_new(t_philo *prev, t_philo *next, int index, char **argv)
{
	t_philo	*result;

	result = malloc(sizeof(t_philo));
	result->next = next;
	result->prev = prev;
	result->index = index;
	result->time = set_argv_time(argv);
	return (result);
}

void	philo_print_list(t_philo *start)
{
	start = philo_get_first(start);
	while (start)
	{
		printf("philoooo nb %d\n", start->index);
		start = start->next;
	}
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
		time_free(start->time);
		free(start);
		start = next;
	}
}

void	philo_sleeping(t_philo *philo)
{
	mutex_print("is sleeping\n", philo);
	usleep(philo->time->time_to_sleep);
	mutex_print("is thinking\n", philo);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_hand->mutex);
	mutex_print("has taken a fork\n", philo);
	pthread_mutex_lock(&philo->left_hand->mutex);
	mutex_print("has taken a fork\n", philo);
	mutex_print("is eating\n", philo);
	philo->time->time_since_last_ate = get_time();
	usleep(philo->time->time_to_eat);
	pthread_mutex_unlock(&philo->right_hand->mutex);
	pthread_mutex_unlock(&philo->left_hand->mutex);
}

void	*philo_check_if_dead(void *args)
{
	t_philo *philo = (t_philo *)args;
	while (42)
	{
		if (get_time_past(philo->time->time_since_last_ate) >= philo->time->time_to_die)
			philo_die(philo);
		philo = philo->next;
	}
}

void	philo_die(t_philo *philo)
{
	mutex_print("has died of hunger\n", philo);
	ft_error("A philosopher is dead\n", 0);
}

void	mutex_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d %s", get_time()->tv_sec, philo->index, str);
	// printf("%ld : philosopher %d %s", get_time()->tv_sec, philo->index, str);
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
