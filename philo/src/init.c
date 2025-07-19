/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:24:31 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/19 15:33:48 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_data(t_data *data)
{
	int i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->finish = FALSE;
	pthread_mutex_init(&data->finish_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	data->forks = malloc(data->n_philo * (sizeof(t_data)));
	if(!data->forks)
		return(FALSE);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
    return(TRUE);
}

int init_philo(t_philo *philo)
{
    
    philo = malloc((philo->data->n_philo) * (sizeof(t_philo)));
	if(!philo)
		return(FALSE);
    if (init_data(philo->data))
        return(FALSE);
	
    return (TRUE);
}