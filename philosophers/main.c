#include "phil.h"

int main(int argc, char *argv[])
{
	int				i;
	t_philo			*ph;
	t_philo_info	*pi;
	i = 0;
	if (argc > 5 || argc < 6)
		return(too_few_arg());
	pi = malloc(sizeof(t_philo_info)* 1);
	if (before_init(pi, argv) == 0)
		return(free_ph(pi));
	
}