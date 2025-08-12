/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:56:51 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/12 13:37:12 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>

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

typedef struct s_philo
{
	struct s_data	*data;	
	int				id;
	int 			n_eaten;
	long long		last_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
    unsigned int	n_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				n_times_eat;
	int 			finish;
	long long		start;
	long long		now_time;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
	pthread_t		monitor;
	t_philo			*philo;
}	t_data;

int	ft_error(char *str);
int	ft_strlen(char *str);
int	input_valid(int argc, char **argv, t_data *data);
int init_philo(t_data *data);
int init_data(int argc, char **argv, t_data *data);
unsigned int ft_atoil(char *str);
unsigned long	get_current_time_ms(void);
void	*philo_routine(void *arg);
void	*admin_routine(void *arg);
void	wait_finish(t_data *data);
void	ft_finish(t_data *data);
void    philo_forks(t_philo *philo);
void    philo_eat(t_philo *philo);
void    philo_think(t_philo *philo);
void    philo_sleep(t_philo *philo);
void	print_msg(char *msg, t_philo *philo, t_data *data);

#endif