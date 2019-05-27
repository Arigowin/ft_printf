#include <libft.h>
#include "ft_printf.h"

size_t		ft_nbrlen(long long int nb)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nb);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}
