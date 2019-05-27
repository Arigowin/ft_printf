#include "libft.h"

size_t	ft_get_index(char *tab, char c)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(tab))
	{
		if (tab[i] == c)
			break ;
		i++;
	}
	return (i);
}
