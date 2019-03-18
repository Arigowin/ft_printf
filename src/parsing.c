#include <stdarg.h>
#include "ft_printf.h"

t_type		check_type(char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STR);
	if (c == 'p')
		return (PTR);
	if (c == 'd')
		return (INT);
	if (c == 'i')
		return (INT);
	if (c == 'o')
		return (OCT);
	if (c == 'u')
		return (UINT);
	if (c == 'x')
		return (LHEX);
	if (c == 'X')
		return (UHEX);
	if (c == 'f')
		return (FLT);
	if (c == '%')
		return (PCT);
	return (DFLT);
}

void		parse(t_lst **lst, const char *format)
{
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i != start)
			{
				lst_add(lst, DFLT, ft_strsub(format, start, i - start));
				start = i;
			}
			while (format[i] && i < ft_strlen(format))
			{
				i++;
				if (ft_strchr("cspdiouxXf%", format[i]) != NULL && i < ft_strlen(format))
				{
					lst_add(lst,
							check_type(format[i]),
							ft_strsub(format, start + 1, (i - start)));
					start = i + 1;
					break ;
				}
			}
		}
		i++;
	}
	if (i != start)
		lst_add(lst, DFLT, ft_strsub(format, start, i - start));
}
