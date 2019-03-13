#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = ft_printf("%lx\n", 4294967296);
	r2 = printf("%lx\n", 4294967296);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("%llX\n", 4294967296);
	r2 = printf("%llX\n", 4294967296);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("%llx\n", 9223372036854775807);
	r2 = printf("%llx\n", 9223372036854775807);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("%llx\n", 9223372036854775808);
	r2 = printf("%llx\n", 9223372036854775808);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = ft_printf("%#llx\n", 9223372036854775807);
	r2 = printf("%#llx\n", 9223372036854775807);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	/* ft_printf("%hd\n", 32768); */
	/* ft_printf("%hhd\n", 128); */
	/* ft_printf("%hhd\n", -129); */
	/* ft_printf("%ld\n", 2147483648); */
	/* ft_printf("%ld\n", -2147483649); */
	/* ft_printf("%lld\n", 9223372036854775807); */
	/* ft_printf("%lld\n", -9223372036854775808); */
	/* ft_printf("%zd\n", 4294967295); */
	/* ft_printf("%zd\n", 4294967296); */
	/* ft_printf("%lu\n", 4294967296); */
	/* ft_printf("%lu\n", -42); */
	/* ft_printf("%llu\n", 4999999999); */
	/* ft_printf("%U\n", 4294967295); */
	/* ft_printf("%hU\n", 4294967296); */
	/* ft_printf("%U\n", 4294967296); */

	return (0);
}
