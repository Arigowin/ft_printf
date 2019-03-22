#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	r1 = printf("%#x\n", -1229617463);
	r2 = ft_printf("%#x\n", -1229617463);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#-51hhx\n", -1229617463);
	r2 = ft_printf("%#-51hhx\n", -1229617463);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%6llx\n", 101123008);
	r2 = ft_printf("%6llx\n", 101123008);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#2.32hhx\n", 0);
	r2 = ft_printf("%#2.32hhx\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%051hhx\n", 0);
	r2 = ft_printf("%051hhx\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%15.2hx\n", -1935111160);
	r2 = ft_printf("%15.2hx\n", -1935111160);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%024hhx\n", 155781241);
	r2 = ft_printf("%024hhx\n", 155781241);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%-#42.24hhx\n", 1696670642);
	r2 = ft_printf("%-#42.24hhx\n", 1696670642);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#34.2hx\n", -1594173284);
	r2 = ft_printf("%#34.2hx\n", -1594173284);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#2hhx\n", -1403054584);
	r2 = ft_printf("%#2hhx\n", -1403054584);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#17.16hhx\n", 1629224528);
	r2 = ft_printf("%#17.16hhx\n", 1629224528);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#8.2llx\n", 56210540);
	r2 = ft_printf("%#8.2llx\n", 56210540);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#56.2hhx\n", -1370165058);
	r2 = ft_printf("%#56.2hhx\n", -1370165058);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#26.43hhx\n", -411639218);
	r2 = ft_printf("%#26.43hhx\n", -411639218);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#27.39hhX\n", -1538344194);
	r2 = ft_printf("%#27.39hhX\n", -1538344194);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%#51.48hhx\n", -1229617463);
	r2 = ft_printf("%#51.48hhx\n", -1229617463);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%0#6hhx\n", 797088827);
	r2 = ft_printf("%0#6hhx\n", 797088827);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%-#2hhx\n", -1386108671);
	r2 = ft_printf("%-#2hhx\n", -1386108671);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%-#2hhx\n", 0);
	r2 = ft_printf("%-#2hhx\n", 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%0#2.4hhx\n", -676257078);
	r2 = ft_printf("%0#2.4hhx\n", -676257078);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	r1 = printf("%-#42.40hhx\n", 381527121);
	r2 = ft_printf("%-#42.40hhx\n", 381527121);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
