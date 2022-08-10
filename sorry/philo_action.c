#include "phil.h"

void philo_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork[ph->id % ph->oldman->nop]);
	my_print(ph, how_long(ph), "has taken a fork");
	pthread_mutex_lock (&ph->fork[ph->id - 1]);
	my_print(ph, how_long(ph), "has taken a fork");
	my_print(ph, how_long(ph), "is eating");
	ph->last_meal = get_time();
	ph->meal += 1;
	if (ph->oldman->df == 0)
		detail_usleep(ph->oldman->tte);
	pthread_mutex_unlock(&ph->fork[ph->id % ph->oldman->nop]);
	pthread_mutex_unlock(&ph->fork[ph->id - 1]);
}

void philo_sleep(t_philo *ph)
{
	my_print(ph, how_long(ph), "is sleeping");
	if (ph->oldman->df == 0)
		detail_usleep(ph->oldman->tts);
}

void philo_think(t_philo *ph)
{
	my_print(ph, how_long(ph), "is thinking");
}