/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:50:12 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/19 15:53:33 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	wait_finish(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo)
	{
		sem_wait(data->stop);
		while (i < (int)data->n_philo)
		{
			kill(data->philo->pid, SIGKILL);
			i++;
		}
	}
	if (data->n_times_eat > -1)
		printf("%lu %s\n", print_time(data), ALL_EATS);
}

void	ft_finish(t_data *data)
{
		sem_close(data->forks);
		sem_unlink("/forks");
		sem_close(data->print_sem);
		sem_unlink("/print");
		sem_close(data->death_sem);
		sem_unlink("/death");
		sem_close(data->stop);
		sem_unlink("/stop");
	if (data->philo)
		free(data->philo);
}

void	*monitor_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)arg;
	while (philo->data->n_times_eat == -1 || ++i < philo->data->n_times_eat)
	{
		if (check_time(philo))
		{
			sem_wait(philo->data->print_sem);
			printf("%lu %d %s\n", print_time(philo->data), philo->id, DIED);
			sem_post(philo->data->stop);
			break ;
		}
	}
	exit(EXIT_FAILURE);
}

void	philo_routine(t_philo *philo)
{
	int i;
	
	i = -1;
	pthread_create(&philo->monitor, NULL,
		monitor_routine, philo);
	while (philo->data->n_times_eat == -1 || ++i < philo->data->n_times_eat)
	{
		if (philo_forks(philo))
			exit(EXIT_FAILURE);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	exit(EXIT_FAILURE);
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
		if (data.philo[i].pid == 0)
			philo_routine(&data.philo[i]);
		i++;
	}
	wait_finish(&data);
	ft_finish(&data);
	return (0);
}
