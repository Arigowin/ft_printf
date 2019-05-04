#include "ft_printf.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*save_ptr;

	i = 0;
	save_ptr = s;
	while (i < n)
	{
		*save_ptr = '\0';
		i++;
		save_ptr++;
	}
}
