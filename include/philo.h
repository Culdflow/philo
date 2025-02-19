/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:15 by dfeve             #+#    #+#             */
/*   Updated: 2025/02/05 18:34:04 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int			nb_times_eat;
	long long	time_project_start;
	long long	time_last_ate;
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
	int				dead;
	int				times_ate;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	*print_mutex;
	t_fork			*right_hand;
	t_fork			*left_hand;
	pthread_t		thread;
	pthread_mutex_t	*is_dead_mutex;
	pthread_mutex_t	*is_eating_mutex;
	pthread_mutex_t	*set_eating_mutex;
	t_time			*time;
}	t_philo;

typedef struct s_all
{
	t_philo			*philo;
	t_fork			*forks;
	int				i;
	pthread_t		check_death_thread;
	pthread_t		check_how_many_times_ate;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	is_eating_mutex;
	pthread_mutex_t	set_eating_mutex;
}	t_all;

//------------------------- PHILO ----------------------------

t_philo		*philo_new(t_philo *prev, t_philo *next, int index, char **argv);
t_philo		*philo_make_lst(int philo_nb, char **argv, t_all *all);
t_philo		*philo_getfrom_index(t_philo *start, int index);
void		philo_free(t_philo	*start);
void		*philo_thread(void *args);
void		philo_die(t_philo *philo);
void		mutex_print(char *str, t_philo *philo);
t_philo		*philo_get_first(t_philo *philo);
void		philo_print_list(t_philo *start);
void		close_threads(t_philo *start, t_all *all);
void		philo_sleeping(t_philo *philo);
void		set_philo_dead(t_philo *philo);
void		check_if_dead(t_philo *philo);
void		*philo_check_if_dead(void *args);
void		philo_set_fork(t_philo *start, t_fork *forks);
void		*philo_check_if_ate_enough(void *args);
void		set_all_struct(t_all **all_struct, char **argv);

//------------------------- FORK -----------------------------

t_fork		*fork_new(t_fork *prev, int index);
t_fork		*fork_make_lst(int nb);
t_fork		*fork_getfrom_index(t_fork *start, int index);
void		fork_free(t_fork *start);
t_fork		*fork_get_first(t_fork *fork);

//------------------------- TIME -----------------------------

long long	get_time(void);

//------------------------ ERROR -----------------------------

void		ft_error(char *str, int error_code);
void		my_usleep(int wait_time, t_philo *philo);

#endif