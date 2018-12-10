#include <stdarg.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	char		*s;
	int			d;
	char		buff[13];

	len = 0;
	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			len++;
		}
		if (*format++ == '%')
		{
			if (*format == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
				len += ft_strlen(s);
			}
			else if (*format == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				len += ft_strlen(ft_itoa(d));
			}
			else if (*format == 'c')
			{
				ft_putchar((char) va_arg(ap, int));
				len++;
			}
			else if (*format == 'p')
			{
				ft_ptr_to_hex(va_arg(ap, void *), &buff);
				ft_putstr("0x");
				ft_putstr(buff);
				len += ft_strlen(buff) + 2;
			}
			else
			{
				ft_putstr("ERROR");
			}
			(void)*format++;
		}
	}

	va_end(ap);
	return (len);
}
