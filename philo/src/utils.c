/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:03:22 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/19 12:52:11 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_atoil(char *str)
{
	int i;
	unsigned int nbr;

	i = 0;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' ||str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if(nbr > UINT_MAX)
			return(FALSE);
		i++;
	}
	return ((unsigned int)nbr);
}

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
		i++;
    return (i);
}

int	ft_error(char *str)
{
	int i;

	i = ft_strlen(str);
	write(2, str, i);
	return(EXIT_FAILURE);
}