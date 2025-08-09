/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:15 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/02 14:04:11 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data data;
    int		i;
	
    if (argc < 5 || argc > 6)
        return (ft_error("ERROR: "));
    if (input_valid(argc, argv, &data))
        return (ft_error("ERROR: Invalid Input"));
	i = 0;
    while(i++ < data.n_philo)
    return (0);
}