/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:25:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 12:35:30 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_fork	*right_hand;
	struct s_fork	*left_hand;
	float			time_since_Last_ate;
}	t_philo;

typedef struct s_fork
{
	int				index;
	struct s_fork	*next;
	struct s_fork	*prev;
	t_philo			*philo;
}	t_fork;

typedef struct s_time
{
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
}	t_time;

//------------------------- PHILO ----------------------------

t_philo	*philo_new(t_philo *prev, t_philo *next, int index);
t_philo	*philo_make_lst(int	philo_nb);
t_philo	*philo_getfrom_index(t_philo *start, int index);
void	philo_free(t_philo	*start);

//------------------------- FORK -----------------------------

t_fork	*fork_new(t_fork *prev, int index);
t_fork	*fork_make_lst(int	nb);
t_fork	*fork_getfrom_index(t_fork *start, int index);
void	fork_free(t_fork *start);

//------------------------- TIME -----------------------------

int	time_time(struct timeval *tv);


#endif