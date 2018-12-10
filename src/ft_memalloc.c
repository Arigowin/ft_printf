#include <stdlib.h>
#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size != 0)
	{
		tmp = malloc(size);
		if (tmp != NULL)
			ft_bzero(tmp, size);
		return (tmp);
	}
	return (NULL);
}
