#include "lem_in.h"

int		loc(t_lst *top, char *end)
{
	t_lst		*len;
	int			i;
	char		**comp;

	i = 1;
	len = top;
	comp = ft_strsplit(len->data, '-');
	while (len)
	{
		if (!ft_strcmp(comp[0], end))
			return (i);
		else if (!ft_strcmp(comp[1], end))
			return (i);
		i++;
		comp = ft_strsplit(len->data, '-');
		len = len->right;
	}
	return (i);
}

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

void		delete_node(t_lst **a, int l)
{
	int		i;
	t_lst	*tmp;
	t_lst	*prev;

	i = 0;
	prev = NULL;
	if (*a == NULL)
		return ;
	tmp = *a;
	while (i < l - 1)
	{
		create_path(&prev, tmp->data);
		tmp = tmp->right;
		i++;
	}
	tmp->right = NULL;
	tmp->left = NULL;
	*a = prev;
	free(tmp);
}

t_lst		*addr_pos(t_lst *a, int loc)
{
	int     i;
	t_lst	*value;

	i = 0;
	value = 0;
	
	while (a && i++ < loc)
	{
		value = a;
		a = a->right;
	}
	return (value);
}

t_lst	*end_to_bottom(t_lst **res, int loc)
{
	int    i= 0;
	t_lst *tmp;
	t_lst *p;
	//t_lst *l_addr;

	//l_addr = addr_pos(*res, ft_lstlen(*res));
	tmp = addr_pos(*res, loc);
	p = *res;
	while (i++ < ft_lstlen(*res))
		p = p->right;
	tmp->right = NULL;
	//p->left = tmp;
	printf("got here\n");
	tmp->left = p;
	return (tmp);
}
void	end_to_end(t_lst **res)
{
	t_lst 	*top;
	t_lst	*end;
	t_lst	*l_addr;
	t_lst	*sec_addr;

	sec_addr = addr_pos(*res, ft_lstlen(*res));
	l_addr = addr_pos(*res, ft_lstlen(*res));
	if (*res == NULL)
		return ;
	top = *res;
	*res = (*res)->right;
	end = top;
	if (ft_lstlen(*res) <= 1)
		return ;
	while (end->right != NULL)
		end = end->right;
	end->right = top;
	top->right = NULL;
	top->left = l_addr;
}

/* t_lst		*do_lst(char *sr, t_lst *res, t_lst *las, t_lst **path)
{
	int cou, j = 0;
	t_lst *temp;
	t_lst *tmp;

	temp = las;
	tmp = (*path);
	while (ft_strcmp(tmp->data, sr))
	{
		*path = search_path1(res, &las);
		tmp = (*path);
		tmp = tmp->right;
		cou++;
	}
	if (!ft_strcmp(las, sr))
	{
		while (temp->left != NULL)
		{
			if (ft_strcmp(sr, ft_strsub(tmp->data, 0, ft_strlen(sr))) == 0)
                    {
                printf("HERE\n");
                        cut = ft_strsplit(tmp->data, '-');
                        if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st)))
                        {
                             cut = ft_strsplit(tmp->data, '-');
                            create_path(&path, cut[0]);
                            st = cut[0];
                        }
                        else
                        { 
                            create_path(&path, cut[1]);
                            st[0] = cut[1];
                        }
                        if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                            return(path);
                    }
                    
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;      
                tmp = tmp->left;
		}
	}
	while (res)
	{
		if (!ft_strcmp(cut[0], sr))
			j++;
	}
	if (j == 0)
		res = res->right;
	if ()
	
} */