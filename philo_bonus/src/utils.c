/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:58:13 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/19 15:59:57 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

unsigned long	get_current_time_ms(void)
{
	struct timeval	tv;
	unsigned long	current_time;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	current_time = ((tv.tv_sec * SEC_TO_MSEC + (tv.tv_usec / MSEC_TO_USEC)));
	return (current_time);
}

unsigned int	ft_atoil(char *str)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > UINT_MAX)
			return (FALSE);
		i++;
	}
	return ((unsigned int)nbr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	exit(EXIT_FAILURE);
}

int	check_time(t_philo *philo)
{
	sem_wait(philo->data->death_sem);
	if (get_current_time_ms() - philo->last_time > philo->data->time_to_die)
	{
		sem_post(philo->data->death_sem);
		return (FALSE);
	}
	sem_post(philo->data->death_sem);
	return (TRUE);
}