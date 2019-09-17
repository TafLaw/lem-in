#include "lem_in.h"

char		*pos(t_lst *a, int loc)
{
	int     i;
	char	*value;

	i = 0;
	value = 0;
	while (a && i++ < loc)
	{
		value = a->data;
		a = a->right;
	}
	return (value);
}