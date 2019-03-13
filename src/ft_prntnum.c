#include "ft_printf.h"

void ft_prntnum(unsigned long num, int base, char sign, char *outbuf)
{
	int i = 19;
	int j = 0;

	while(num > 0 || i == 19)
	{
		outbuf[i] = "0123456789abcdef"[num % base];
		i--;
		num = num/base;
	}
	if(sign != ' ')
	{
		outbuf[0] = sign;
		++j;
	}
	while( ++i < 20)
		outbuf[j++] = outbuf[i];
	outbuf[j] = 0;
}
