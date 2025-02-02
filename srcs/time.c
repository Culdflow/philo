/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:25:37 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/02 23:00:34 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

float	get_time_past(struct timeval *tv)
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	return (real_time.tv_sec - tv->tv_sec);
}

struct timeval	*get_time()
{
	struct timeval	*real_time;

	real_time = malloc(sizeof(struct timeval));
	gettimeofday(real_time, NULL);
	return (real_time);
}

void	time_free(t_time *time)
{
	free(time->time_since_last_ate);
	free(time);
}