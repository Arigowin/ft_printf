#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("%.56f\n", 6321776);
	r2 = ft_printf("%.56f\n", 6321776);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("!%20.36f!\n", 6321776);
	r2 = ft_printf("!%20.36f!\n", 6321776);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("!%42.63lf!\n", 0.000000);
	r2 = ft_printf("!%42.63lf!\n", 0.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("42%42.62lf42\n", 0.000000);
	r2 = ft_printf("42%42.62lf42\n", 0.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%2f\n", 0.000000);
	r2 = ft_printf("%2f\n", 0.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("\\!/% 44.42lf\\!/\n", 0.000000);
	r2 = ft_printf("\\!/% 44.42lf\\!/\n", 0.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
