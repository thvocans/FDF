#include <stdio.h>

int	main(int ac, char **av)
{
	FILE *f = fopen(av[1], "r");
	double d;
	double sum;
	int i;
	while (fscanf(f, "%lf\n",&d) > 0)
	{
		sum += d;
		i++;
	}
	printf("%.9g, %d",sum / i, i);
}
