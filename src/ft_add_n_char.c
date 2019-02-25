#include "ft_printf.h"

void		ft_add_n_char(char **str, char c, int n)
{
	int		i;

	i = 0;
	while (str && *str && i < n)
	{
		(*str)[i] = c;
		i++;
	}
}
