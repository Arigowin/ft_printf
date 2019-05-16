#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int		main(void)
{
	int		r1;
	int		r2;

	setbuf(stdout, NULL);

	printf("-------------------------------------\n");
	ft_printf("(\"abc %%% [%%c] [%%s] [%%p] def\\n\", 0, NULL, NULL)\n");
	r1 = printf("abc %% [%c] [%s] [%p] def\n", 0, NULL, NULL);
	r2 = ft_printf("abc %% [%c] [%s] [%p] def\n", 0, NULL, NULL);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	char *tmp = malloc(50 * sizeof(char));
	ft_printf("(\"abc %%% [%%c] [%%s] [%%p] def\\n\", 42, \"42\", tmp)\n");
	r1 = printf("abc %% [%c] [%s] [%p] def\n", 42, "42", tmp);
	r2 = ft_printf("abc %% [%c] [%s] [%p] def\n", 42, "42", tmp);
	free(tmp);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	unsigned ui = 0;
	ft_printf("(\"abc [%%d] [%%i] [%%o] [%%u] [%%x] [%%X] def\\n\", 0, 0, 0, 0, 0, 0)\n");
	r1 = printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 0, 0, 0, ui, 0, 0);
	r2 = ft_printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 0, 0, ui, 0, 0, 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ui = 42;
	ft_printf("(\"abc [%%d] [%%i] [%%o] [%%u] [%%x] [%%X] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 42, 42, 42, ui, 42, 42);
	r2 = ft_printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 42, 42, 42, ui, 42, 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	long l = 42;
	unsigned long ul = 42;
	ft_printf("(\"abc [%%ld] [%%li] [%%lo] [%%lu] [%%lx] [%%lX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%ld] [%li] [%lo] [%lu] [%lx] [%lX] def\n", l, l, ul, ul, ul, ul);
	r2 = ft_printf("abc [%ld] [%li] [%lo] [%lu] [%lx] [%lX] def\n", l, l, ul, ul, ul, ul);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	long long ll = 42;
	unsigned long long ull = 42;
	ft_printf("(\"abc [%%lld] [%%lli] [%%llo] [%%llu] [%%llx] [%%llX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%lld] [%lli] [%llo] [%llu] [%llx] [%llX] def\n", ll, ll, ull, ull, ull, ull);
	r2 = ft_printf("abc [%lld] [%lli] [%llo] [%llu] [%llx] [%llX] def\n", ll, ll, ull, ull, ull, ull);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	short s = 42;
	unsigned short us = 42;
	ft_printf("(\"abc [%%hd] [%%hi] [%%ho] [%%hu] [%%hx] [%%hX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%hd] [%hi] [%ho] [%hu] [%hx] [%hX] def\n", s, s, us, us, us, us);
	r2 = ft_printf("abc [%hd] [%hi] [%ho] [%hu] [%hx] [%hX] def\n", s, s, us, us, us, us);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	char c = 42;
	unsigned char uc = 42;
	ft_printf("(\"abc [%%hhd] [%%hhi] [%%hho] [%%hhu] [%%hhx] [%%hhX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%hhd] [%hhi] [%hho] [%hhu] [%hhx] [%hhX] def\n", c, c, uc, uc, uc, uc);
	r2 = ft_printf("abc [%hhd] [%hhi] [%hho] [%hhu] [%hhx] [%hhX] def\n", c, c, uc, uc, uc, uc);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%f] [%%f] [%%f] [%%f] def\\n\", 0.0, 42.42, 42.0, 1.42)\n");
	r1 = printf("abc [%f] [%f] [%f] [%f] def\n", 0.0, 42.42, 42.0, 1.42);
	r2 = ft_printf("abc [%f] [%f] [%f] [%f] def\n", 0.0, 42.42, 42.0, 1.42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%lf] [%%lf] [%%lf] [%%lf] delf\\n\", 0.0, 42.42, 42.0, 1.42)\n");
	r1 = printf("abc [%lf] [%lf] [%lf] [%lf] def\n", 0.0, 42.42, 42.0, 1.42);
	r2 = ft_printf("abc [%lf] [%lf] [%lf] [%lf] def\n", 0.0, 42.42, 42.0, 1.42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%lf] [%%lf] [%%lf] def\\n\", 0.0, 42.42, 42.0)\n");
	r1 = printf("abc [%lf] [%lf] [%lf] def\n", 0.0, 42.42, 42.0);
	r2 = ft_printf("abc [%lf] [%lf] [%lf] def\n", 0.0, 42.42, 42.0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%f] [%%Lf] [%%Lf] [%%Lf] def\\n\", 0.0, 42.42, 42.0\n");
	r1 = printf("abc [%f] [%Lf] [%Lf] def\n", 0.0, (long double)42.42, (long double)42.0);
	r2 = ft_printf("abc [%f] [%Lf] [%Lf] def\n", 0.0, (long double)42.42, (long double)42.0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("\"abc [%%d] [%%0d] [%%010d] [%%010.3d] [%%+d] [%%+d] [%%-d] [%%-d] [%% d] [%% d]\\n\", 42, 42, 42, 42, 42, -42, 42, -42, 42, -42\n");
	r1 = printf("abc [%d] [%0d] [%010d] [%010.3d] [%+d] [%+d] [%-d] [%-d] [% d] [% d]\n", 42, 42, 42, 42, 42, -42, 42, -42, 42, -42);
	r2 = ft_printf("abc [%d] [%0d] [%010d] [%010.3d] [%+d] [%+d] [%-d] [%-d] [% d] [% d]\n", 42, 42, 42, 42, -42, 42, 42, -42, 42, -42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("\"abc [%%f] [%%020.10f] [%%20.10f]\\n\", 42.42, 42.42, 42.42\n");
	r1 = printf("abc [%f] [%020.10f] [%20.10f]\n", 42.42, 42.42, 42.42);
	r2 = ft_printf("abc [%f] [%020.10f] [%20.10f]\n", 42.42, 42.42, 42.42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("\"abc [%%x] [%%#x] [%%#o] [%%#o]\\n\", 10, 10, 10, 10\n");
	r1 = printf("abc [%x] [%#x] [%#o] [%#o]\n", 10, 10, 10, 10);
	r2 = ft_printf("abc [%x] [%#x] [%#o] [%#o]\n", 10, 10, 10, 10);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
