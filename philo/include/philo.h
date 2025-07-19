/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:56:51 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:14 by rfleritt         ###   ########.fr       */
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
}	t_data;

typedef struct s_philo
{
	int				id;
	int 			n_eaten;
	long long		last_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

int	ft_error(char *str);
int	ft_strlen(char *str);
int	input_valid(int argc, char **argv, t_data *data);
int ft_atoil(char *str);
int init_philo(t_philo *philo);

#endif