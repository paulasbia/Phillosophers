/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulabiazotto <paulabiazotto@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:54:04 by paulabiazot       #+#    #+#             */
/*   Updated: 2023/10/18 11:25:35 by paulabiazot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		printf("passou %d thread %d\n", i, *(int *)arg);
		i++;
	}
	free(arg);
	return (NULL);
}

int	start_thread(int num_philo)
{
	pthread_t	*th;
	int			i;
	int			*a;

	i = 0;
	th = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
	while (i < num_philo)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			error_msg("Failed to create thread");
		i++;
	}
	i = 0;
	while (i < num_philo)
	{
		if (pthread_join(th[i], NULL) != 0)
			error_msg("Failed to join thread!");
		i++;
	}
	return (0);
}