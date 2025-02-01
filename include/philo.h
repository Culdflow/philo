/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:25:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 11:40:39 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
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

#endif