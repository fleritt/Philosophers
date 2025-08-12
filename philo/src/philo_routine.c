/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:06:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/12 14:07:22 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int    look_finish(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->finish_mutex);
    if(philo->data->finish == 0)
    {
        pthread_mutex_unlock(&philo->data->finish_mutex);
        return (TRUE);
    }
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return(FALSE);
}

void    philo_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->left_fork);
        print_msg(TAKE_FORKS, philo, philo->data);
        pthread_mutex_lock(philo->right_fork);
        print_msg(TAKE_FORKS, philo, philo->data);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        print_msg(TAKE_FORKS, philo, philo->data);
        pthread_mutex_lock(philo->left_fork);
        print_msg(TAKE_FORKS, philo, philo->data);
    }
}

void    philo_eat(t_philo *philo)
{
    print_msg(EAT, philo, philo->data);
    philo->last_time = get_current_time_ms();
    philo->n_eaten++;
    usleep(philo->data->time_to_eat * MSEC_TO_USEC);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}

void    philo_think(t_philo *philo)
{
    print_msg(THINK, philo, philo->data);
}

void    philo_sleep(t_philo *philo)
{
    print_msg(SLEEP, philo, philo->data);
    usleep(philo->data->time_to_sleep * MSEC_TO_USEC);
}