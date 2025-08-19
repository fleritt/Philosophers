/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:21:44 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/19 15:43:59 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

unsigned long	print_time(t_data *data)
{
	return (get_current_time_ms() - data->start);
}

void	print_msg(char *msg, t_philo *philo, t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lu %d %s\n", print_time(data), philo->id, msg);
	sem_post(data->print_sem);
}