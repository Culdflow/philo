/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:50:22 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 09:54:43 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_fork	*fork_new()
{
	t_fork	*result;

	result = malloc(sizeof(t_fork));
	result->philo = NULL;
	result->next = NULL;
	return (result);
}

t_fork	*fork_make_lst(int	nb)
{
	int		i;
	t_fork	*fork;
	t_fork	*result;

	fork = fork_new();
	result = fork;
	i = 0;
	while (i++ < nb)
	{
		fork->next = fork_new();
		fork = fork->next;
	}
	return (result);
}