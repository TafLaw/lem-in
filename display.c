#include "lem_in.h"

void	trav(t_lst *top)
{
	t_lst *temp;

	if (top == NULL)
		ft_putendl("EMPTY");
	else
	{
		temp = top;
		while (temp != NULL)
		{
			ft_putstr(temp->data);
			ft_putstr(" -> ");
			temp = temp->right;
		}
		ft_putendl("NULL");
	}
}