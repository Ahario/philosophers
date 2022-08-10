/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:41:33 by hyeo              #+#    #+#             */
/*   Updated: 2022/07/27 15:41:35 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	before_init(t_philo_info *pi, char *gv[])
{
	if (check_alpha(gv) == 1)
		return (1);
	pi->nop = ft_atoi(gv[1]);
	pi->ttd = ft_atoi(gv[2]);
	pi->tte = ft_atoi(gv[3]);
	pi->tts = ft_atoi(gv[4]);
	if (gv[5])
		pi->notepme = ft_atoi(gv[5]);
	else
		pi->notepme = -1;
	pi->df = 0;
	pi->birth = get_time();
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, 0);
	return ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
}

int	check_alpha(char *gv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (gv[i] != NULL)
	{
		j = 0;
		while (gv[i][j] != '\0')
		{
			if (gv[i][j] >= '0' && gv[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
