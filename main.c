#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int r1;
	int r2;

	setbuf(stdout, NULL);

	printf("-----------------------\n");
	r1 = ft_printf("abc\n");
	r2 = printf("abc\n");
	printf("\nMy %d, %d\n", r1, r2);

	printf("-----------------------\n");
	r1 = ft_printf("%d\n", 42);
	r2 = printf("%d\n", 42);
	printf("\nMy %d, %d\n", r1, r2);

	printf("-----------------------\n");
	r1 = ft_printf("%+d\n", 42);
	r2 = printf("%+d\n", 42);
	printf("\nMy %d, %d\n", r1, r2);

	printf("-----------------------\n");
	r1 = ft_printf("%+d\n", -42);
	r2 = printf("%+d\n", -42);
	printf("\nMy %d, %d\n", r1, r2);

	printf("-----------------------\n");
	r1 = ft_printf("%s\n", "abc");
	r2 = printf("%s\n", "abc");
	printf("\nMy %d, %d\n", r1, r2);

	char *abc;
	printf("-----------------------\n");
	abc = (char *) malloc(sizeof(char) * 5);
	r1 = ft_printf("%p\n", abc);
	r2 = printf("%p\n", abc);
	free(abc);
	printf("\nMy %d, %d\n", r1, r2);

	printf("-----------------------\n");
	r1 = ft_printf("%f\n", 1.);
	r2 = printf("%f\n", 1.);
	printf("\nMy %d, %d\n", r1, r2);

	r2 = ft_printf("%1defdef");
	r2 = ft_printf("");
	r2 = ft_printf(NULL);
	return (0);
}
