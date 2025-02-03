/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:24:49 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 00:29:10 by dfeve            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int				i;
	t_all			*all_struct;
	pthread_mutex_t	print_mutex;

	if (argc < 5)
		ft_error("Wrong number of arguments", 1);
	all_struct = malloc(sizeof(t_all));
	i = -1;
	if (ft_atoi(argv[1]) > 0)
	{
		pthread_mutex_init(&print_mutex, NULL);
		all_struct->print_mutex = print_mutex;
		all_struct->forks = fork_make_lst(ft_atoi(argv[1]));
		all_struct->philo = philo_make_lst(ft_atoi(argv[1]), argv, all_struct->forks, &all_struct->print_mutex);
		philo_print_list(all_struct->philo);
		create_philo_checkifdead_thread(all_struct->philo, all_struct);
		while (++i < ft_atoi(argv[1]))
		{
			printf("looking for index: %d\n", i);
			create_philo_thread(philo_getfrom_index(all_struct->philo, i));
		}
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
	while (start)
	{
		pthread_join(start->thread, NULL);
		start = start->next;
	}
}
