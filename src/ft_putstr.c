#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	while (s && i < ft_strlen(s))
	{
		ft_putchar(s[i]);
		i++;
	}
}
