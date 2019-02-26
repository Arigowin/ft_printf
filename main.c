#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	/* printf("-------------------------------------\n"); */
	/* r1 = ft_printf("%c\n", 42); */
	/* r2 = printf("%c\n", 42); */
	/* printf("%d, %d\n", r1, r2); */
	/* printf("-------------------------------------\n"); */

	printf("-------------------------------------\n");
	r1 = ft_printf("%4.15s\n", "I am 42");
	r2 = printf("%4.15s\n", "I am 42");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("%4.15s\n", "42 is the answer");
	r2 = printf("%4.15s\n", "42 is the answer");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("{%-30d}\n", 10000);
	r2 = printf("{%-30d}\n", 10000);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	return (0);
}
