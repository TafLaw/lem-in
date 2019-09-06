#include "lem_in.h"

int		ft_lstlen(t_lst *r)
{
	t_lst		*temp;
	int			len;

	temp = r;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->right;
	}
	return (len);
}