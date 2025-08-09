/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:56:51 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/21 18:01:07 by rfleritt         ###   ########.fr       */
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

typedef struct s_philo
{
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
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
	t_philo			*philo;
}	t_data;

int	ft_error(char *str);
int	ft_strlen(char *str);
int	input_valid(int argc, char **argv, t_data *data);
int ft_atoil(char *str);
int init_philo(t_data *data);
int init_data(t_data *data);
unsigned long	get_current_time_ms(void);

#endif