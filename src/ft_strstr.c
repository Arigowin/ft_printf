#include <string.h>
#include "ft_printf.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	const char	*save_ptr;
	const char	*save_ptr_2;

	save_ptr_2 = s2;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		save_ptr = s1;
		while (*save_ptr == *save_ptr_2)
		{
			save_ptr++;
			save_ptr_2++;
			if (*save_ptr_2 == '\0')
				return ((char*)s1);
		}
		save_ptr_2 = s2;
		s1++;
	}
	return (NULL);
}
