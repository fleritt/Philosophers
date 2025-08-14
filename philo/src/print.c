/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:45:20 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/14 15:14:24 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long	print_time(t_data *data)
{
	return (get_current_time_ms() - data->start);
}

void	print_msg(char *msg, t_philo *philo, t_data *data)
{
	if (look_finish(data))
		return ;
	pthread_mutex_lock(&data->print_mutex);
	printf("%lu %d %s\n", print_time(data), philo->id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
