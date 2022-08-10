/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:41:41 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/27 15:41:42 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	observer(t_philo *ph, t_philo_info *pi)
{
	int				i;
	unsigned long	curr;
	unsigned int	j;

	i = 0;
	while (pi->df == 0)
	{
		curr = get_time();
		j = curr - ph[i].last_meal;
		if (curr > ph[i].last_meal)
		{
			if (j > (unsigned)ph[i].oldman->ttd)
			{
				my_print(&ph[i], how_long(&ph[i]), "died");
				pi->df = 1;
			}
		}
		if (ph->oldman->notepme >= 0)
		{
			if (check_full(ph) == 0)
				pi->df = 1;
		}
		i = (i + 1) % ph[i].oldman->nop;
	}
}

void	detail_usleep(int ttt)
{
	struct timeval	time;
	unsigned long	target_time;
	unsigned long	now_time;

	target_time = 0;
	gettimeofday(&time, 0);
	target_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	now_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	target_time += ttt;
	while (target_time > now_time)
	{
		usleep(100);
		gettimeofday(&time, 0);
		now_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	}
}

void	free_everything(t_philo *ph, t_philo_info *pi, pthread_t *thrd)
{
	int	i;

	i = 0;
	while (i < pi->nop)
	{
		pthread_join(thrd[i], NULL);
		i++;
	}
	free(pi);
	free(ph);
	free(thrd);
}

void	dinner_time(t_philo *ph, pthread_t *thrd)
{
	int	i;

	i = 0;
	while (i != ph->oldman->nop)
	{
		pthread_create(&thrd[i], NULL, ets, ph + i);
		i++;
		usleep(20);
	}
}

int	check_full(t_philo *ph)
{
	int	i;

	i = 0;
	while (ph[i].meal >= ph->oldman->notepme && i < ph->oldman->nop)
		i++;
	if (i == ph->oldman->nop)
		return (0);
	return (1);
}
