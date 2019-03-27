#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("%15.15lf\n", 1.000000);
	r2 = ft_printf("%15.15lf\n", 1.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%34.8lf\n", 1.000000);
	r2 = ft_printf("%34.8lf\n", 1.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
