/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:34:50 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/19 15:52:45 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <pthread.h>

# define FALSE 1
# define TRUE 0

# define PHILO_MAX 200

# define SEC_TO_USEC 1000000
# define SEC_TO_MSEC 1000
# define MSEC_TO_USEC 1000

# define TAKE_FORKS "has taken a fork"
# define EAT "is eating"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define DIED "died"
# define ALL_EATS "all eat enough"

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				n_eaten;
	long long		last_time;
	pthread_t		monitor;
	pid_t			pid;
}	t_philo;

typedef struct s_data
{
	unsigned int	n_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				n_times_eat;
	long long		start;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*death_sem;
	sem_t			*stop;
	t_philo			*philo;
}   t_data;

unsigned long	get_current_time_ms(void);
unsigned long	print_time(t_data *data);
unsigned int	ft_atoil(char *str);
int				ft_strlen(char *str);
int				valid_int(char *str);
int				init_philo(t_data *data);
int				philo_forks(t_philo *philo);
int				check_time(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_think(t_philo *philo);
void			philo_sleep(t_philo *philo);
void    		init_data(int argc, char **argv, t_data *data);
void			ft_error(char *str);
void			input_valid(int argc, char **argv, t_data *data);
void			philo_routine(t_philo *philo);
void			*monitor_routine(void *arg);
void			wait_finish(t_data *data);
void			ft_finish(t_data *data);
void			print_msg(char *msg, t_philo *philo, t_data *data);

#endif