/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 05:00:37 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 03:34:03 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(char *str, int error_code)
{
	ft_printf("\e[1;31m[ERROR]\e[0m : ");
	ft_printf("%s\n", str);
	exit(error_code);
}

void	my_usleep(int wait_time, t_philo *philo)
{
	long long	start_time;

	start_time = get_time();
	while ((int)(get_time() - start_time) < wait_time)
	{
		usleep(100);
		check_if_dead(philo);
	}
}