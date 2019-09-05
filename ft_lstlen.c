#include "lem_in.h"

int		ft_lstlen(t_in *r)
{
	t_in		*temp;
	int			len;

	temp = r;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}