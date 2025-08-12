/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:15 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/12 13:50:40 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_finish(t_data *data)
{
	int i;
	
	i = 0;
	if(data->monitor)
		pthread_join(data->monitor, NULL);
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
}

void	*monitor_routine(void *arg)
{
	t_data *data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while(i < (int)data->n_philo)
		{
			pthread_mutex_lock(&data->finish_mutex);
    		if(data->finish == 0)
    		{
    		    pthread_mutex_unlock(&data->finish_mutex);
    		    return (NULL);
    		}
    		pthread_mutex_unlock(&data->finish_mutex);
			if(get_current_time_ms() - data->philo[i].last_time > data->time_to_die)
    		{
				pthread_mutex_lock(&data->finish_mutex);
    		    data->finish = 0;
    		    pthread_mutex_unlock(&data->finish_mutex);
				print_msg(DIED, &data->philo[i], data);
				return(NULL);
    		}
		}
	}
	return(NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->finish_mutex);
    	if(philo->data->finish == 0)
    	{
    	    pthread_mutex_unlock(&philo->data->finish_mutex);
    	    return (NULL);
    	}
		pthread_mutex_unlock(&philo->data->finish_mutex);
		philo_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return(NULL);
}

int main(int argc, char **argv)
{
	t_data data;
    int		i;
	
	i = 0;
    if (argc < 5 || argc > 6)
	{
        return (ft_error("ERROR: "));
	}
	if (init_data(argc, argv, &data))
		return (ft_error("ERROR: Failed Inicialization"));
    while(i < (int)data.n_philo)
	{
		pthread_create(&data.philo[i].thread, NULL, philo_routine, &data.philo[i]);
		i++;
	}
	pthread_create(&data.monitor, NULL, monitor_routine, &data);
	wait_finish(&data);
	ft_finish(&data);
    return (0);
}
