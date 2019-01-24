#include <stdlib.h>
#include "ft_printf.h"

t_lst		*lst_add(t_lst **lst, void *elt, t_type type, char *str)
{
	t_lst	*new;
	t_lst	*tmp;

	if (str == NULL || lst == NULL)
		return (NULL);
	if ((new = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->elt = elt;
	new->type = type;
	new->str = str;
	new->next = NULL;
	if (*lst == NULL )
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_lst		*lst_add_flt(t_lst **lst, double elt, t_type type, char *str)
{
	t_lst	*new;
	t_lst	*tmp;

	if (str == NULL || lst == NULL)
		return (NULL);
	if ((new = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->elt = NULL;
	new->flt = elt;
	new->type = type;
	new->str = str;
	new->next = NULL;
	if (*lst == NULL )
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

void		lst_free(t_lst **lst)
{
	t_lst	*tmp;

	tmp = NULL;
	while (lst && *lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_strdel(&(tmp->str));
		free(tmp);
	}
	tmp = NULL;
	*lst = NULL;
}
