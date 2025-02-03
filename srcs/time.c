/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:25:37 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/04 00:24:56 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time()
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	return ((real_time.tv_sec * 1000) + (real_time.tv_usec / 1000));
}