/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:24:49 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/05 18:36:03 by dfeve            ###   ########.fr       */
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
	pthread_create(&all->check_how_many_times_ate,
		NULL, philo_check_if_ate_enough, philo);
}

int	main(int argc, char **argv)
{
	t_all			*all_struct;

	all_struct = NULL;
	if (argc < 5 || argc > 6)
		ft_error("Wrong number of arguments", 1);
	if (ft_atoi(argv[1]) > 0)
	{
		set_all_struct(&all_struct, argv);
		create_philo_checkifdead_thread(all_struct->philo, all_struct);
		if (argc == 6)
			create_philo_checkifateenough_thread(all_struct->philo, all_struct);
		while (++all_struct->i < ft_atoi(argv[1]))
			create_philo_thread(philo_getfrom_index(all_struct->philo,
					all_struct->i));
	}
	else
		ft_error("a valid number of philosophers is needed", 1);
	close_threads(all_struct->philo, all_struct);
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
	philo_free(all->philo);
	fork_free(all->forks);
	free(all);
}
