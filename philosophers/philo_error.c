#include "phil.h"

int too_few_arg(void)
{
	printf("You either have more than 6 args or fewer than 5args\n");
	return(1);
}

int free_ph(t_philo_info *ph)
{
	free(ph);
	return(1);
}