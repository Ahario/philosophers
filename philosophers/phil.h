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
	pthread_mutex_t	*print;
	int				id;
	int				meal;
	unsigned long	last_meal;
} t_philo;

long long	ft_atoi(const char *str);
int too_few_arg(void);
int free_pi(t_philo_info *pi);
int free_ph_pi(t_philo *ph, t_philo_info *pi);
int mutex_error(t_philo_info *pi, pthread_mutex_t *f, pthread_mutex_t *p);

int before_init(t_philo_info *pi, char *gv[]);
unsigned long get_time(void);
int check_alpha(char *gv[]);

int init_philo(t_philo *ph, t_philo_info *pi);
int check_mutex(t_philo_info * pi, pthread_mutex_t *f, pthread_mutex_t *p);
void *ets(void *one_ph);
unsigned long how_long(t_philo *ph);
void my_print(t_philo *ph, unsigned long time, char *word);


void observer(t_philo *ph);


#endif