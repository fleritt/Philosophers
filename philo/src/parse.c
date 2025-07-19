/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:03:33 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/19 15:28:47 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int valid_int(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\r' ||str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			return (FALSE);
		i++;
	}
	while (str[i])
	{
		if(str[i] <= '0' && str[i] >= '9')
			return (FALSE);
		i++;
	}
	return(TRUE);
}

int input_valid(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (valid_int(argv[i]))
			return (FALSE);
		i++;
	}
	data->n_philo = ft_atoil(argv[1]);
	data->time_to_die = ft_atoil(argv[2]);
	data->time_to_eat = ft_atoil(argv[3]);
	data->time_to_sleep = ft_atoil(argv[4]);
	data->n_times_eat = -1;
	if(argc == 6)
		data->n_philo = ft_atoil(argv[5]);
	if (data->n_philo > PHILO_MAX)
		return(ft_error("ERROR: The maximum philo is 200"));
	if (data->n_philo <= 0 || data->n_times_eat <= 0 || data->time_to_die <= 0 ||
			data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (FALSE);
    return(TRUE);
}
