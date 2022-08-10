/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:40:42 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/27 15:40:43 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	main(int argc, char *argv[])
{
	int				i;
	t_philo			*ph;
	t_philo_info	*pi;
	pthread_t		*thrd;
	unsigned int	curr;

	i = 0;
	if (argc < 5 || argc > 6)
		return (too_few_arg());
	pi = malloc(sizeof(t_philo_info) * 1);
	if (before_init(pi, argv) == 1)
		return (free_pi(pi));
	ph = malloc(sizeof(t_philo) * pi->nop);
	if (init_philo(ph, pi) == 1)
		return (free_ph_pi(ph, pi));
	thrd = malloc(sizeof(pthread_t) * pi->nop);
	curr = get_time();
	while (i != pi->nop)
		ph[i++].last_meal = curr;
	dinner_time(ph, thrd);
	observer(ph, pi);
	free_everything(ph, pi, thrd);
	return (0);
}
