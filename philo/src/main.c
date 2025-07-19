/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:15 by rfleritt          #+#    #+#             */
/*   Updated: 2025/07/19 14:30:40 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_philo philo;
	
    if (argc < 5 || argc > 6)
        return (ft_error(" "));
    if (input_valid(argc, argv, &philo.data))
        return (ft_error("ERROR: Invalid Input"));
	if (init_philo(&philo))
		return ("ERROR: Failed Inicialization");
    return (0);
}