#include "ft_printf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	i = 0;
	while (s && i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
