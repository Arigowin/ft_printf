#include <libft.h>
#include "ft_printf.h"

void	ft_putupper(char const *s)
{
	size_t i;

	i = 0;
	while (s && i < ft_strlen(s))
	{
		ft_putchar(ft_toupper(s[i]));
		i++;
	}
}
