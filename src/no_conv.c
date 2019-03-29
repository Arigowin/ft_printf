#include <stdlib.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, va_list ap)
{
	(void)ap;
	/* if (ft_strchr(lst->str, '%')) */
	/* { */
	/*     char   *buff; */
	/*     size_t i; */
	/*     size_t j; */
    /*  */
	/*     i = 0; */
	/*     j = 0; */
	/*     buff = ft_strnew(ft_strlen(lst->str)); */
	/*     while (i < ft_strlen(lst->str)) */
	/*     { */
	/*         if (!ft_strchr("lh", (lst->str)[i])) */
	/*             buff[j++] = (lst->str)[i]; */
	/*         i++; */
	/*     } */
	/*     ft_putstr(buff); */
	/*     return (ft_strlen(buff)); */
	/* } */
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

