/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:15 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/14 15:34:06 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_finish(t_data *data)
{
	int	i;

	i = 0;
	if (data->monitor)
		pthread_join(data->monitor, NULL);
	if (data->philo)
	{
		while (i < (int)data->n_philo)
		{
			pthread_join(data->philo[i].thread, NULL);
			i++;
		}
	}
	if (data->n_times_eat > -1)
		printf("%lu %s\n", print_time(data), ALL_EATS);
}

void	ft_finish(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->finish_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	while (i < (int)data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = -1;
	while (data->n_times_eat == -1 || ++i < data->n_times_eat)
	{
		i = 0;
		while (i < (int)data->n_philo)
		{
			if (look_finish(data))
			{
				printf("%lu %d %s\n", print_time(data), data->philo[i].id, DIED);
				return (NULL);
			}
			if (check_time(data, i))
				return (NULL);
		}
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = -1;
	while (philo->data->n_times_eat == -1 || ++i < philo->data->n_times_eat)
	{
		if (look_finish(philo->data))
			return (NULL);
		philo_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		return (ft_error("ERROR: "));
	}
	if (init_data(argc, argv, &data))
		return (ft_error("ERROR: Invalid Input"));
	while (i < (int)data.n_philo)
	{
		pthread_create(&data.philo[i].thread, NULL,
			philo_routine, &data.philo[i]);
		i++;
	}
	pthread_create(&data.monitor, NULL, monitor_routine, &data);
	wait_finish(&data);
	ft_finish(&data);
	return (0);
}
