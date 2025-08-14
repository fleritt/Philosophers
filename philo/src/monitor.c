/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:08 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/14 15:45:13 by rfleritt         ###   ########.fr       */
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
	if (get_current_time_ms() - data->philo[i].last_time > data->time_to_die)
	{
		data->finish = 0;
		pthread_mutex_unlock(&data->finish_mutex);
		printf("%lu %d %s\n", print_time(data), data->philo[i].id, DIED);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->finish_mutex);
	return (FALSE);
}
