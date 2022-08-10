/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:41:05 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/27 15:41:06 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	init_philo(t_philo *ph, t_philo_info *pi)
{
	int				i;
	pthread_mutex_t	*f;
	pthread_mutex_t	*p;

	i = 0;
	f = malloc(sizeof(pthread_mutex_t) * pi->nop);
	p = malloc(sizeof(pthread_mutex_t) * 1);
	if (check_mutex(pi, f, p) == 1)
		free_ph_pi(ph, pi);
	while (i != pi->nop)
	{
		ph[i].fork = f;
		ph[i].print = p;
		ph[i].id = i + 1;
		ph[i].last_meal = 0;
		ph[i].meal = 0;
		ph[i].oldman = pi;
		i++;
	}
	return (0);
}

int	check_mutex(t_philo_info *pi, pthread_mutex_t *f, pthread_mutex_t *p)
{
	int	i;

	i = 0;
	while (i != pi->nop)
	{
		if (pthread_mutex_init(&f[i], NULL))
			return (mutex_error(pi, f, p));
		i++;
	}
	if (pthread_mutex_init(p, NULL))
		return (mutex_error(pi, f, p));
	return (0);
}

void	*ets(void *one_ph)
{
	t_philo			*ph;

	ph = (t_philo *)one_ph;
	if (ph->id % 2 == 0)
		usleep(1000);
	while (ph->oldman->df == 0)
	{
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	return (0);
}

unsigned long	how_long(t_philo *ph)
{
	struct timeval	time;
	unsigned long	start;

	gettimeofday(&time, 0);
	start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (start - ph->oldman->birth);
}

void	my_print(t_philo *ph, unsigned long time, char *word)
{
	pthread_mutex_lock(ph->print);
	usleep(10);
	if (ph->oldman->df == 0)
		printf("%ld %d %s\n", time, ph->id, word);
	pthread_mutex_unlock(ph->print);
}
