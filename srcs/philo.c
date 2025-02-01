/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:39:41 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 11:44:56 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*philo_new(t_philo *prev, t_philo *next, int index)
{
	t_philo	*result;

	result = malloc(sizeof(t_philo));
	result->right_hand = NULL;
	result->left_hand = NULL;
	result->next = next;
	result->prev = prev;
	result->index = index;
	return (result);
}

t_philo	*philo_make_lst(int	philo_nb)
{
	int		i;
	t_philo	*result;
	t_philo	*og;

	i = 0;
	result = philo_new(NULL, NULL, 0);
	og = result;
	while (i++ < philo_nb)
	{
		result->next = philo_new(result, NULL, i + 1);
		result = result->next;
	}
	result->next = og;
	og->prev = result;
	return (og);
}

t_philo	*philo_getfrom_index(t_philo *start, int index)
{
	while (start->index > start->prev->index)
	{
		if (start->index == index)
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	philo_free(t_philo	*start)
{
	t_philo	*next;

	start->prev->next = NULL;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
