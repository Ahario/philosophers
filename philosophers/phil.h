#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo_info
{
	int					nop;
	int					ttd;
	int					tte;
	int					tts;
	int				notepme;
	unsigned long	birth;
}	t_philo_info;

typedef struct s_philo
{
	t_philo_info *oldman;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*printf;
	int				id;
	int				meal;
	unsigned long	last_meal;
} t_philo;

#endif