#include "ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	while (s && (*s != c) && (*s != '\0'))
		s++;
	if (!s || *s != c)
		return (NULL);
	return ((char*)s);
}
