/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:50:12 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/25 10:39:09 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	wait_finish(t_data *data)
{
	int	i;

	i = 0;
	sem_wait(data->stop);
	while (i < (int)data->n_philo)
	{
		kill(data->philo[i].pid, SIGKILL);
		i++;
	}
}

void	ft_finish(t_data *data)
{
		sem_close(data->forks);
		sem_close(data->print_sem);
		sem_close(data->death_sem);
		sem_close(data->stop);
	if (data->philo)
		free(data->philo);
}

void	*monitor_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)arg;
	while (1)
	{
		if (check_time(philo))
		{
			if (philo->n_eaten != philo->data->n_times_eat || philo->data->n_philo != 1)
			{
				sem_wait(philo->data->print_sem);
				printf("%lu %d %s\n", print_time(philo->data), philo->id, DIED);
			}
			sem_post(philo->data->stop);
			return (NULL);
		}
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	int i;
	
	i = 0;
	pthread_create(&philo->monitor, NULL,
		monitor_routine, philo);
	pthread_detach(philo->monitor);
	while (philo->data->n_times_eat == -1 || i < philo->data->n_times_eat)
	{
		philo_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		i++;
	}
	sem_post(philo->data->stop);
}

int	main(int argc, char **argv)
{
    t_data	data;
	int 	i;
    
	i = 0;
    if (argc < 5 || argc > 6)
		ft_error("ERROR: ");
    init_data(argc, argv, &data);
	while (i < (int)data.n_philo)
	{
		data.philo[i].pid = fork();
		if (data.philo[i].pid < 0)
		{
			printf("Error: ");
		}
		if (data.philo[i].pid == 0)
		{
			philo_routine(&data.philo[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_finish(&data);
	ft_finish(&data);
	return (0);
}
