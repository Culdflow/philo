/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:24:49 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 05:09:26 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philo_thread(t_philo *philo)
{
	if (!philo)
		return ;
	pthread_create(&philo->thread, NULL, philo_thread, philo);
}

void	create_philo_checkifdead_thread(t_philo *philo, t_all *all)
{
	if (!philo)
		return ;
	pthread_create(&all->check_death_thread, NULL, philo_check_if_dead, philo);
}

void	create_philo_checkifateenough_thread(t_philo *philo, t_all *all)
{
	if (!philo)
		return ;
	pthread_create(&all->check_how_many_times_ate, NULL, philo_check_if_ate_enough, philo);
}

int	main(int argc, char **argv)
{
	int				i;
	t_all			*all_struct;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	is_eating_mutex;
	pthread_mutex_t	set_eating_mutex;

	if (argc < 5 || argc > 6)
		ft_error("Wrong number of arguments", 1);
	all_struct = malloc(sizeof(t_all));
	i = -1;
	if (ft_atoi(argv[1]) > 0)
	{
		pthread_mutex_init(&print_mutex, NULL);
		pthread_mutex_init(&is_dead_mutex, NULL);
		pthread_mutex_init(&is_eating_mutex, NULL);
		pthread_mutex_init(&set_eating_mutex, NULL);
		all_struct->print_mutex = print_mutex;
		all_struct->is_dead_mutex = is_dead_mutex;
		all_struct->is_eating_mutex = is_eating_mutex;
		all_struct->set_eating_mutex = set_eating_mutex;
		all_struct->forks = fork_make_lst(ft_atoi(argv[1]));
		all_struct->philo = philo_make_lst(ft_atoi(argv[1]), argv, all_struct);
		create_philo_checkifdead_thread(all_struct->philo, all_struct);
		if (argc == 6)
			create_philo_checkifateenough_thread(all_struct->philo, all_struct);
		while (++i < ft_atoi(argv[1]))
			create_philo_thread(philo_getfrom_index(all_struct->philo, i));
	}
	else
		ft_error("a valid number of philosophers is needed", 1);
	close_threads(all_struct->philo, all_struct);
	philo_free(all_struct->philo);
	fork_free(all_struct->forks);
	free(all_struct);
}

void	close_threads(t_philo *start, t_all *all)
{
	start = philo_get_first(start);
	pthread_join(all->check_death_thread, NULL);
	pthread_join(all->check_how_many_times_ate, NULL);
	while (start)
	{
		pthread_join(start->thread, NULL);
		start = start->next;
	}
}
