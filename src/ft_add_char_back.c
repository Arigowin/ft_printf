#include "ft_printf.h"

void		ft_add_char_back(char c, char **str, int nb, int start)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		(*str)[start + i] = c;
		i++;
	}
	(*str)[start + i] = '\0';
}
