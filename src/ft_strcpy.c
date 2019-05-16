#include "ft_printf.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	char	*save_ptr;

	save_ptr = s1;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	s1 = save_ptr;
	return (s1);
}
