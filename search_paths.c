#include "lem_in.h"

void		search_paths(t_lst	**res, char	**sr, char	**first, t_lst	**path, t_lst ** las)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (path == NULL)
	{
		ft_putstr("here");
		create_links(path, *sr);
		return ;
	}
	else
	{
		tmp = *res;
		while (tmp)
		{
			if (ft_strcmp(*first, ft_strreturn(tmp->data, *first)) == 0 && ft_strcmp(*sr, ft_strreturn(tmp->data, *sr)))
			{
				create_links(path, *first);
				*sr = ft_strdup(*first);
				return ;
			}
			tmp = tmp->right;
		}
		if (tmp == NULL)
		{
			tmp2 = *las;
			while (tmp)
			{
				if (ft_strcmp(*first, ft_strreturn(tmp->data, *first)) == 0 && ft_strcmp(*sr, ft_strreturn(tmp->data, *sr)))
				{
					create_links(path, *first);
					*sr = ft_strdup(*first);
					return ;
				}
				tmp2 = tmp2->left;
			}
		}
		*first = ft_strdup("noend");
	}
}

int		check_dup(t_lst	*path)
{
	t_lst	*tmp;

	if (path == NULL)
		return (0);
	while (path)
	{
		tmp = path->right;
		while (tmp)
		{
			if (ft_strcmp(path->data, tmp->data) == 0)
			{
				return (1);
			}
			tmp = tmp->right;
		}
		path = path->right;
	}
	return (0);
}
