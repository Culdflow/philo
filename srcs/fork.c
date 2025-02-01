/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:50:22 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 12:36:54 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_fork	*fork_new(t_fork *prev, int index)
{
	t_fork	*result;

	result = malloc(sizeof(t_fork));
	result->philo = NULL;
	result->next = NULL;
	result->prev = prev;
	result->index = index;
	return (result);
}

t_fork	*fork_make_lst(int	nb)
{
	int		i;
	t_fork	*fork;
	t_fork	*result;

	fork = fork_new(NULL, 0);
	result = fork;
	i = 0;
	while (i++ < nb)
	{
		fork->next = fork_new(fork, i + 1);
		fork = fork->next;
	}
	fork->next = result;
	result->prev = fork;
	return (result);
}

t_fork	*fork_getfrom_index(t_fork *start, int index)
{
	while (start->index > start->prev->index)
	{
		if (start->index == index)
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	fork_free(t_fork *start)
{
	t_fork	*next;

	start->prev->next = NULL;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}