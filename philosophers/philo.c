#include "phil.h"

int main(int argc, char *argv[])
{
	int				i;
	t_philo			*ph;
	t_philo_info	*pi;
	pthread_t		*thrd;

	i = 0;
	if (argc < 5 || argc > 6)
		return(too_few_arg());
	pi = malloc(sizeof(t_philo_info) * 1);
	printf("hi\n");
	if (before_init(pi, argv) == 1)
		return(free_pi(pi));
	printf("hi\n");
	ph = malloc(sizeof(t_philo) * pi->nop);
	if (init_philo(ph, pi) == 1)
		return(free_ph_pi(ph, pi));
	printf("hi\n");
	thrd = malloc(sizeof(pthread_t) * pi->nop);
	while(i != pi->nop)
	{
		pthread_create(&thrd[i], NULL, ets, (void*) ph + i);
		i++;
	}
	usleep(1000);
	observer(ph);
}