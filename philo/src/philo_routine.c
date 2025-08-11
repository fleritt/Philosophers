/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:06:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/11 14:22:06 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    philo_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->left_fork);
        print_msg(TAKE_FORKS, philo->data);
        pthread_mutex_lock(&philo->right_fork);
        print_msg(TAKE_FORKS, philo->data);
    }
    else
    {
        pthread_mutex_lock(&philo->right_fork);
        print_msg(TAKE_FORKS, philo->data);
        pthread_mutex_lock(&philo->left_fork);
        print_msg(TAKE_FORKS, philo->data);
    }
}
void    philo_eat(t_philo *philo)
{
    print_msg(EAT, philo->data);
    philo->last_time = get_current_time_ms();
    philo->n_eaten++;
    pthread_mutex_unlock(&philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);
}
void    philo_think(t_philo *philo)
{
    
}

void    philo_sleep(t_philo *philo)
{
    print_msg(SLEEP, philo->data);
    usleep(philo->data->time_to_sleep * MSEC_TO_USEC);
}