/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:50:22 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/03 00:52:09 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_fork	*fork_new(t_fork *prev, int index)
{
	t_fork	*result;

	result = malloc(sizeof(t_fork));
	pthread_mutex_init(&result->mutex, NULL);
	result->next = NULL;
	result->prev = prev;
	result->index = index;
	return (result);
}

t_fork	*fork_get_first(t_fork *fork)
{
	while (fork->prev)
		fork = fork->prev;
	return (fork);
}

t_fork	*fork_make_lst(int	nb)
{
	int		i;
	t_fork	*fork;
	t_fork	*result;

	fork = fork_new(NULL, 0);
	result = fork;
	i = 0;
	while (i < nb)
	{
		fork->next = fork_new(fork, i++);
		fork = fork->next;
	}
	return (result);
}

t_fork	*fork_getfrom_index(t_fork *start, int index)
{
	t_fork	*fstart;

	fstart = fork_get_first(start);
	while (fstart)
	{
		if (fstart->index == index)
			return (fstart);
		fstart = fstart->next;
	}
	return (NULL);
}

void	fork_free(t_fork *start)
{
	t_fork	*next;

	start = fork_get_first(start);
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}