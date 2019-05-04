#include <stdlib.h>
#include "ft_printf.h"

char				*ft_strdup(const char *s1)
{
	size_t			i;
	char			*duplicate;
	size_t			str_len;

	i = 0;
	str_len = ft_strlen(s1);
	duplicate = (char*)malloc(str_len + 1);
	if (!duplicate)
		return (NULL);
	while (i < str_len)
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
