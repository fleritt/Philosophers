/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:15 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/11 13:25:30 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_finish(t_data *data)
{
	int i;
	
	i = 0;
	if(data->admin)
		pthread_join(data->admin, NULL);
	if(data->philo)
	{
		while(i < (int)data->n_philo)
		{
			pthread_join(data->philo[i].thread, NULL);
			i++;
		}
	}
}

void	ft_finish(t_data *data)
{
	int i;

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
	free(data);
}

void	*admin_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	return(NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	philo_forks(philo);
	philo_eat(philo);
	philo_think(philo);
	philo_sleep(philo);
	return(NULL);
}

int main(int argc, char **argv)
{
	t_data *data;
    int		i;
	
	i = 0;
	data = malloc(sizeof(t_data));
    if (argc < 5 || argc > 6)
        return (ft_error("ERROR: "));
    if (input_valid(argc, argv, data))
        return (ft_error("ERROR: Invalid Input"));
    while(i < (int)data->n_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, philo_routine, &data->philo[i]);
		i++;
	}
	pthread_create(&data->admin, NULL, admin_routine, &data);
	wait_finish(data);
	ft_finish(data);
    return (0);
}
