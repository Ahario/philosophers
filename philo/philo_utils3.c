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

void	observer(t_philo *ph)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (1)
	{
		j = get_time() - ph[i].last_meal;
		if (j > (unsigned)ph[i].oldman->ttd)
		{
			usleep(10);
			printf("%u %u\n", j, (unsigned)ph[i].oldman->ttd);
			my_print(&ph[i], how_long(&ph[i]), "died");
			break ;
		}
		j = 0;
		if (ph[i].oldman->notepme != -1)
		{
			while ((unsigned)ph[j].meal == (unsigned)ph[i].oldman->nop)
				j++;
			if (j == (unsigned)ph[i].oldman->nop)
				break ;
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
		usleep(10);
		gettimeofday(&time, 0);
		now_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	}
}

void	free_everything(t_philo *ph, t_philo_info *pi, pthread_t *thrd)
{
	free(ph);
	free(pi);
	free(thrd);
}
