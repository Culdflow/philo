/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:24:49 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 12:34:57 by dfeve            ###   ########.fr       */
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
	return (result);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	time_time(&tv);
}