#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = ft_printf("%c\n", 42);
	r2 = printf("%c\n", 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
