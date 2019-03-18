#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("%hhU\n", 4294967295);
	r2 = ft_printf("%hhU\n", 4294967295);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla % BLABLABLABLA\n");
	r2 = ft_printf("Bla bla % BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %#BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %#BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %-BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %-BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %+BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %+BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %0BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %0BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %3BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %3BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %10BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %10BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %.BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %.BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %.0BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %.0BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %.3BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %.3BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("Bla bla %.10BLABLABLABLA\n");
	r2 = ft_printf("Bla bla %.10BLABLABLABLA\n");
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
