#include <stdlib.h>
#include "ft_printf.h"

char		*ft_strsub(char const *s, size_t start, size_t len)
{
	size_t		cpt;
	char		*tmp;

	cpt = 0;
	tmp = NULL;
	if (s != NULL && start < ft_strlen(s))
	{
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp != NULL)
		{
			while (s[start + cpt] != '\0' && cpt < len)
			{
				tmp[cpt] = s[start + cpt];
				cpt++;
			}
			tmp[cpt] = '\0';
		}
	}
	return (tmp);
}
