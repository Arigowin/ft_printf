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
	r1 = printf("%#62.4hho\n", -283999378);
	r2 = ft_printf("%#62.4hho\n", -283999378);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#2.2hho\n", 141107286);
	r2 = ft_printf("%#2.2hho\n", 141107286);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%-#2.2hho\n", -342326644);
	r2 = ft_printf("%-#2.2hho\n", -342326644);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
