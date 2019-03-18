#include "ft_printf.h"

static void		ft_putunbr(unsigned long long int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void			ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putunbr(-n);
	}
	else
		ft_putunbr(n);
}
