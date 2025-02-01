/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:25:37 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 12:38:02 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	time_time(struct timeval *tv)
{
	struct timeval	real_time;
	
	(void)tv;
	gettimeofday(&real_time, NULL);
	printf("Seconds since 1/1/1970: %lu\n",real_time.tv_usec);
	return (0);
}