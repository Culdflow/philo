/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:25:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/03 01:04:54 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_time
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	struct timeval	*time_since_last_ate;
}	t_time;

typedef struct s_fork
{
	int				index;
	struct s_fork	*next;
	struct s_fork	*prev;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				index;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	*print_mutex;
	t_fork			*right_hand;
	t_fork			*left_hand;
	pthread_t		thread;
	t_time			*time;
}	t_philo;

typedef struct s_all
{
	t_philo			*philo;
	t_fork			*forks;
	pthread_mutex_t	print_mutex;
}	t_all;

//------------------------- PHILO ----------------------------

t_philo	*philo_new(t_philo *prev, t_philo *next, int index, char **argv);
t_philo	*philo_make_lst(int	philo_nb, char **argv, t_fork *forks, pthread_mutex_t *print_mutex);
t_philo	*philo_getfrom_index(t_philo *start, int index);
void	philo_free(t_philo	*start);
void	*philo_thread(void *args);
void	philo_die(t_philo *philo);
void	mutex_print(char *str, t_philo *philo);
t_philo	*philo_get_first(t_philo *philo);
void	philo_print_list(t_philo *start);
void	close_threads(t_philo *start);

//------------------------- FORK -----------------------------

t_fork	*fork_new(t_fork *prev, int index);
t_fork	*fork_make_lst(int	nb);
t_fork	*fork_getfrom_index(t_fork *start, int index);
void	fork_free(t_fork *start);
t_fork	*fork_get_first(t_fork *fork);

//------------------------- TIME -----------------------------

float			get_time_past(struct timeval *tv);
void			time_free(t_time *time);
struct timeval	*get_time();

//------------------------ ERROR -----------------------------

void	ft_error(char *str, int error_code);

#endif