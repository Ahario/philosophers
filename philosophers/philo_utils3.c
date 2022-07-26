#include "phil.h"

void observer(t_philo *ph)
{
	int				i;
	int				j;

	i = 0;
	while (1)
	{
		j = get_time()  - ph[i].last_meal;
		printf("%ld %ld %d\n", get_time(), ph[i].last_meal, j);
		if (j > ph[i].oldman->ttd)
		{
			printf("%d %d\n", j, ph[i].oldman->ttd);
			my_print(&ph[i], how_long(&ph[i]), "died");
			break;
		}
		j = 0;
		if (ph[i].oldman->notepme)
		{
			while (j != ph[i].oldman->nop)
			{
 				if (ph[j].meal >= ph[j].oldman->notepme)
					j++;
				else
					break;
			}
			if (j == ph[i].oldman->nop)
				break;
		}
		i = (i + 1) % ph[i].oldman->nop;
	}
}
