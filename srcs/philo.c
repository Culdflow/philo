/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:39:41 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 09:59:55 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*philo_new(t_philo *prev, t_philo *next)
{
	t_philo	*result;

	result = malloc(sizeof(t_philo));
	result->right_hand = NULL;
	result->left_hand = NULL;
	result->next = next;
	result->prev = prev;
	return (result);
}

t_philo	*philo_make_lst(int	philo_nb)
{
	int		i;
	t_philo	*result;
	t_philo	*og;

	i = 0;
	result = philo_new(NULL, NULL);
	og = result;
	while (i++ < philo_nb)
	{
		result->next = philo_new(result, NULL);
		result = result->next;
	}
	return (og);
}

void	philo_free(t_philo	*start)
{
	
}