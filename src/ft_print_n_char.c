#include <libft.h>
#include "ft_printf.h"

void		ft_print_n_char(char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}
