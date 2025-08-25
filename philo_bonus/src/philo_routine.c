/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:19:18 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/25 10:37:06 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	philo_forks(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
        sem_wait(philo->data->forks);
    	print_msg(TAKE_FORKS, philo, philo->data);
    	usleep(philo->data->time_to_die * MSEC_TO_USEC);
		printf("%lu %d %s\n", print_time(philo->data), philo->id, DIED);
    	sem_post(philo->data->stop);
	}
	else if (philo->id % 2 == 0)
		usleep(1000);
	sem_wait(philo->data->forks);
	print_msg(TAKE_FORKS, philo, philo->data);
    sem_wait(philo->data->forks);
	print_msg(TAKE_FORKS, philo, philo->data);
	return (TRUE);
}

void	philo_eat(t_philo *philo)
{
    sem_wait(philo->data->death_sem);
	philo->last_time = get_current_time_ms();
    sem_post(philo->data->death_sem);
	print_msg(EAT, philo, philo->data);
	philo->n_eaten++;
	usleep(philo->data->time_to_eat * MSEC_TO_USEC);
    sem_post(philo->data->forks);
    sem_post(philo->data->forks);
}

void	philo_think(t_philo *philo)
{
	print_msg(THINK, philo, philo->data);
}

void	philo_sleep(t_philo *philo)
{
	print_msg(SLEEP, philo, philo->data);
	usleep(philo->data->time_to_sleep * MSEC_TO_USEC);
}