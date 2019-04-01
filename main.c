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
	ft_printf("(\"abc [%%d] [%%i] [%%o] [%%u] [%%x] [%%X] def\\n\", 0, 0, 0, 0, 0, 0)\n");
	r1 = printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 0, 0, 0, 0, 0, 0);
	r2 = ft_printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 0, 0, 0, 0, 0, 0);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%d] [%%i] [%%o] [%%u] [%%x] [%%X] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 42, 42, 42, 42, 42, 42);
	r2 = ft_printf("abc [%d] [%i] [%o] [%u] [%x] [%X] def\n", 42, 42, 42, 42, 42, 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%ld] [%%li] [%%lo] [%%lu] [%%lx] [%%lX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%ld] [%li] [%lo] [%lu] [%lx] [%lX] def\n", 42, 42, 42, 42, 42, 42);
	r2 = ft_printf("abc [%ld] [%li] [%lo] [%lu] [%lx] [%lX] def\n", 42, 42, 42, 42, 42, 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%lld] [%%lli] [%%llo] [%%llu] [%%llx] [%%llX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%lld] [%lli] [%llo] [%llu] [%llx] [%llX] def\n", 42, 42, 42, 42, 42, 42);
	r2 = ft_printf("abc [%lld] [%lli] [%llo] [%llu] [%llx] [%llX] def\n", 42, 42, 42, 42, 42, 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%hd] [%%hi] [%%ho] [%%hu] [%%hx] [%%hX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%hd] [%hi] [%ho] [%hu] [%hx] [%hX] def\n", 42, 42, 42, 42, 42, 42);
	r2 = ft_printf("abc [%hd] [%hi] [%ho] [%hu] [%hx] [%hX] def\n", 42, 42, 42, 42, 42, 42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");
	ft_printf("(\"abc [%%hhd] [%%hhi] [%%hho] [%%hhu] [%%hhx] [%%hhX] def\\n\", 42, 42, 42, 42, 42, 42)\n");
	r1 = printf("abc [%hhd] [%hhi] [%hho] [%hhu] [%hhx] [%hhX] def\n", 42, 42, 42, 42, 42, 42);
	r2 = ft_printf("abc [%hhd] [%hhi] [%hho] [%hhu] [%hhx] [%hhX] def\n", 42, 42, 42, 42, 42, 42);
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
	ft_printf("(\"abc [%%Lf] [%%Lf] [%%Lf] [%%Lf] deLf\\n\", 0.0, 42.42, 42.0, 1.42)\n");
	r1 = printf("abc [%Lf] [%Lf] [%Lf] [%Lf] def\n", 0.0, 42.42, 42.0, 1.42);
	r2 = ft_printf("abc [%Lf] [%Lf] [%Lf] [%Lf] def\n", 0.0, 42.42, 42.0, 1.42);
	printf("%d, %d\n", r1, r2);
	printf("-------------------------------------\n");

	return (0);
}
