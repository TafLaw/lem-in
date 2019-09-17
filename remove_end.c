#include "lem_in.h"

void		remove_end(t_lst **path)
{
	int		k;
	t_lst	*tmp;
	t_lst	*tmp2;

	k = ft_lstlen(*path);
	tmp = *path;
	while (tmp && ft_strcmp(tmp->data, pos(*path, k)) != 0)
	{
		tmp = tmp->right;
	}
	tmp2 = tmp->left;
	tmp2->right = NULL;
	free(tmp);
	tmp = *path;
}

void        delete_node(t_lst **a, int l)
{
    int        i;
    t_lst    *tmp;
    t_lst    *prev;
    i = 0;
    prev = NULL;
    if (*a == NULL)
        return ;
    tmp = *a;
    while (i < l - 1)
    {
        create_links(&prev, tmp->data);
        tmp = tmp->right;
        i++;
    }
    tmp->right = NULL;
    tmp->left = NULL;
    *a = prev;
    free(tmp);
}
