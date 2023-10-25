/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:21:31 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/10/25 10:18:50 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_start	start;

	if (check_args(ac, av) == 1)
		return (1);
	lets_start(&start, av, ac);
	start.forks = create_table(&start, av, ac);
	start_thread(start);
	ft_lstclear(&start.forks);
}
