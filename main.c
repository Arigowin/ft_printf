#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	/* printf("-------------------------------------\n"); */
	/* r1 = printf("%60.57lf\n", 1.000000); */
	/* r2 = ft_printf("%60.57lf\n", 1.000000); */
	/* printf("%d, %d\n", r1, r2); */
	printf("-------------------------------------\n");
	r1 = printf("42% 2.2hhd42\n", 0);
	r2 = ft_printf("42% 2.2hhd42\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("42%021.2hhd42\n", -956069262);
	r2 = ft_printf("42%021.2hhd42\n", -956069262);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("^.^/%044hhd^.^/\n", 0);
	r2 = ft_printf("^.^/%044hhd^.^/\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("\\!/% -58.7hhd\\!/\n", 0);
	r2 = ft_printf("\\!/% -58.7hhd\\!/\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
