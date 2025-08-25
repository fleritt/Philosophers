/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:08 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/25 09:58:41 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	look_finish(t_data *data)
{
	pthread_mutex_lock(&data->finish_mutex);
	if (data->finish == 0)
	{
		pthread_mutex_unlock(&data->finish_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&data->finish_mutex);
	return (TRUE);
}

int	check_time(t_data *data, int i)
{
	pthread_mutex_lock(&data->finish_mutex);
	pthread_mutex_lock(&data->meal_mutex);
	if (get_current_time_ms() - data->philo[i].last_time > data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		data->finish = 0;
		pthread_mutex_unlock(&data->finish_mutex);
		pthread_mutex_lock(&data->meal_mutex);
		if (data->philo[i].n_eaten != data->n_times_eat)
			printf("%lu %d %s\n", print_time(data), data->philo[i].id, DIED);
		pthread_mutex_unlock(&data->meal_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&data->finish_mutex);
	pthread_mutex_unlock(&data->meal_mutex);
	return (TRUE);
}
