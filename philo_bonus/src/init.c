/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:12:09 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/25 10:29:38 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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
        data->philo[i].n_eaten = 0;
        data->start = get_current_time_ms();
        data->philo[i].last_time = data->start;
        data->philo[i].data = data;
        i++;
    }
    return (TRUE);
}

void	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	memset(data, '\0', sizeof(t_data));
	input_valid(argc, argv, data);
	i = 0;
	if (!data)
		ft_error("ERROR: Invalid Input");
    sem_unlink("/forks");
    sem_unlink("/print");
    sem_unlink("/death");
    sem_unlink("/stop");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->n_philo);
	data->print_sem = sem_open("/print", O_CREAT, 0644, 1);
    data->death_sem = sem_open("/death", O_CREAT, 0644, 1);
    data->stop = sem_open("/stop", O_CREAT, 0644, 0);
	if (init_philo(data))
		ft_error("ERROR: Malloc");
}
