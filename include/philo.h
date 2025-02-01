/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:25:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/01 09:42:48 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>

typedef struct s_philo
{
	struct s_philo	next;
	struct s_philo	prev;
	struct s_fork	*right_hand;
	struct s_fork	*left_hand;
}	t_philo;

typedef struct s_fork
{
	struct s_fork	next;
	t_philo	*philo;
}	t_fork;

#endif