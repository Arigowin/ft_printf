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
		return (STR);
	if (c == 'o')
		return (STR);
	if (c == 'u')
		return (STR);
	if (c == 'x')
		return (STR);
	if (c == 'X')
		return (STR);
	return (DFLT);
}

void		parse(t_lst **lst, va_list ap, const char *format)
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
				lst_add(lst, NULL, DFLT, ft_strsub(format, start, i - start));
				start = i;
			}
			while (format[i])
			{
				if (ft_strchr("cspdiouxX", format[i]) != NULL)
				{
					lst_add(lst, va_arg(ap, void *),
							check_type(format[i]),
							ft_strsub(format, start + 1, (i - start)));
					start = i + 1;
					break ;
				}
				i++;
			}
		}
		i++;
	}
	if (i != start)
		lst_add(lst, NULL, DFLT, ft_strsub(format, start, i - start));
}
