/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:40:58 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/27 15:40:59 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	too_few_arg(void)
{
	printf("You either have more than 6 args or fewer than 5args\n");
	return (1);
}

int	free_pi(t_philo_info *pi)
{
	free(pi);
	return (1);
}

int	free_ph_pi(t_philo *ph, t_philo_info *pi)
{
	free(ph);
	free(pi);
	return (1);
}

int	mutex_error(t_philo_info *pi, pthread_mutex_t *f, pthread_mutex_t *p)
{
	int	i;

	i = 0;
	while (i != pi->nop)
	{
		pthread_mutex_destroy(&f[i]);
		i++;
	}
	pthread_mutex_destroy(p);
	return (1);
}
