#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("%42.6hho\n", 1865805488);
	r2 = ft_printf("%42.6hho\n", 1865805488);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
