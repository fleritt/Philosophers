/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:24:31 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/18 13:26:12 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc((data->n_philo) * (sizeof(t_philo)));
	if (!data->philo)
		return (FALSE);
	while (i < (int)data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->n_philo];
		data->philo[i].n_eaten = 0;
		data->start = get_current_time_ms();
		data->philo[i].last_time = data->start;
		data->philo[i].data = data;
		i++;
	}
	return (TRUE);
}

int	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	memset(data, '\0', sizeof(t_data));
	if (input_valid(argc, argv, data))
		return (ft_error("ERROR: Invalid Input"));
	i = 0;
	if (!data)
		return (FALSE);
	data->finish = FALSE;
	data->forks = malloc(data->n_philo * (sizeof(pthread_mutex_t)));
	if (!data->forks)
		return (FALSE);
	while (i < (int)data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->finish_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	if (init_philo(data))
		return (FALSE);
	return (TRUE);
}
