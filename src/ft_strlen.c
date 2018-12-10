#include <string.h>
#include "ft_printf.h"

size_t			ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	if (s)
		while (*s != '\0')
		{
			count++;
			s++;
		}
	return (count);
}
