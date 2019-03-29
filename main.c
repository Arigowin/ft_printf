#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("% #031.2lf\n", 0.000000);
	r2 = ft_printf("% #031.2lf\n", 0.000000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
