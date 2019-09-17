/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:02 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/09/15 16:51:57 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
t_lst *las = NULL;

void    create_links(t_lst **p, char *da)
{
    t_lst *temp;
    t_lst *t;

    temp = (t_lst *)malloc(sizeof(t_lst));
    temp->data = ft_strdup(da);
    temp->right = NULL;
    temp->left = NULL;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
        las = temp;
        temp->left = t;   
    }
}

void    create_path(t_lst **p, char *da)
{
    t_lst *temp;
    t_lst *t;

    temp = (t_lst *)malloc(sizeof(t_lst));
    temp->data = ft_strdup(da);
    temp->right = NULL;
    temp->left = NULL;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
        temp->left = t;   
    }
}

size_t p_len(char *str)
{
    size_t i = 0;

    while (str[i] != '-')
        i++;
    return (i);
}

size_t s_len(char *str)
{
    size_t i = 0;
    size_t j = 0;

    while (str[i] != '-')
        i++;
    while(str[i++])
        j++;
    return (j);
}

void    single_paths(t_in **p, char *s)
{
    t_in *temp;
    t_in *t;

    temp = (t_in *)malloc(sizeof(t_in));
    temp->data = ft_strdup(s);
    temp->next = NULL;;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;   
    }
}

/* void    links(char *str, t_lst **path, t_in **res)
{
    char **pre;
    int  i;
    
    i = 0;
    pre = ft_strsplit(str, '-');
    single_paths(res, pre[i]);
    trav2(*res);
    printf("%d\n", duplicate(*res, pre[i]));
    if (duplicate(*res, pre[i]) == 0)
    {
        printf("no dup\n");
        if (*path == NULL)
        {
            create_path(path, pre[i]);
            create_path(path, pre[i+1]);
            
        }
        else   if (duplicate2(*path, pre[i + 1]) == 0 || duplicate2(*path, pre[i]) == 0)
                create_path(path, pre[i+1]);
      trav(*path);
    }
    if (duplicate(*res, pre[i]) == 1)
    {
        printf("dup\n");
      trav(*path);
        return ;
    }
    free(pre);
} */
/*
int      check_links(t_lst *res, char *s)
{
    while ()
}*/

t_lst    *search_path(t_lst  *res, char *s, char *e)
{
    char **st;
    char **en;
    char **cut;
    t_lst *tmp;
    t_lst *path;
	t_lst	*visited;
	t_lst	**adr;
	int		k;

   adr = NULL;
   path = NULL;
   visited = NULL;
    st = ft_strsplit(s, ' ');
    en = ft_strsplit(e, ' ');
        if (path == NULL)
            create_path(&path, st[0]);
        tmp = res;
        while (1)
        {
            while (tmp)
            {
				if (check_dup(path) == 1 || search_end(visited, st[0]) == 1)
                {
                    break ;
                }
                if (ft_strcmp(st[0],ft_strreturn(tmp->data, st[0])) == 0)
                {
                    cut = ft_strsplit(tmp->data, '-');
                    if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])))
                    {
                         cut = ft_strsplit(tmp->data, '-');
                        create_path(&path, cut[0]);
                        st[0] = cut[0];
                    }
                    else
                    {
                       create_path(&path, cut[1]);
                        st[0] = cut[1];
                    }
                    if (ft_strcmp(pos(path, ft_lstlen(path)), en[0]) ==0)
                        return (path);
                }
                tmp = tmp->right;
            }
			if (tmp == NULL)
            {
                tmp = las;
                while (tmp)
                {
					if (check_dup(path) == 1 || search_end(visited, st[0]) == 1)
					{
						break ;
					}
                    if (ft_strcmp(st[0], ft_strsub(tmp->data, 0, ft_strlen(st[0]))) == 0)
                    {
                        cut = ft_strsplit(tmp->data, '-');
                        if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])))
                        {
                             cut = ft_strsplit(tmp->data, '-');
                            create_path(&path, cut[0]);
                            st[0] = cut[0];
                        }
                        else
                        { 
                            create_path(&path, cut[1]);
                            st[0] = cut[1];
                        }
                        if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                            return(path);
						//adr = path;
                    }
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;
			tmp = tmp->left;
                }
            }
			adr = &path;
            //printf("check1 == %s\n", adr->right->data);
			//printf("end %s\n", st[0]);
			//printf("end2 %s\n", path->left->data);
			//printf("checks == %d", check_dup(path));
			if (search_end(path, en[0]) != 1 || check_dup(path) == 1 || search_end(visited, st[0]) == 1)
            {
                create_links(&visited, st[0]);
				//printf("visited == %s", st[0]);	
				k = ft_lstlen(*adr);
				delete_node(adr, k);
				trav(*adr);
				k = ft_lstlen(*adr);
				if(search_end(visited, st[0]) == 1)
				{
					delete_node(adr, k);
					k = /*ft_lstlen(*adr)*/ k - 1;
					//printf("k == %d", k);
				}
				st[0] = ft_strdup(pos(*adr, k));
				//printf("sr == %s", st[0]);
				path = *adr;
				tmp = res;
            }
			/*
           char **posi;
            posi = ft_strsplit(pos(res, ft_lstlen(res)), '-');
            if (!ft_strcmp(posi[1], en[0]) || !ft_strcmp(posi[0], en[0]))
                break;
            break;*/
        }
    return (path);
}

int			search(t_lst *res, char *sr, t_lst	**visited)
{
	t_lst 	*temp;
	int	  	result;
	char  **save;

	temp = res;
	result = 0;
	while (temp != NULL)
	{
		if (ft_strcmp(sr, ft_strreturn(temp->data, sr)) == 0)
		{
			save = ft_strsplit(temp->data, '-');
			if (ft_strcmp(save[0], sr) != 0)
			{
				create_links(visited, save[0]);
			}
			else if (ft_strcmp(save[1], sr) != 0)
			{
				create_links(visited, save[1]);
			}
			result = result + 1;
		}
		temp = temp->right;
	}
	trav(*visited);
	//printf("result == %d\n", result);
	return (result);
}

int			search_end(t_lst *path, char *en)
{
	t_lst	*tmp;

	tmp = path;
	if(path == NULL)
	{
		return (0);
	}
	while (tmp->right != NULL)
	{
		if (ft_strcmp(tmp->data, en) == 0)
		{
			return (1);
		}
		tmp = tmp->right;
	}
	return (0);
}
/*
t_lst		*paths(t_lst **res, char *sr, char *en, t_lst *las)
{
	t_lst			*visited;
	t_lst			*path;
	static char		*first;
	static char		**save;
	int				n;
	int				p;
	
	p = 0;
	visited = NULL;
	path = NULL;
	first = NULL;
	las = NULL;
	en = NULL;
	save = ft_strsplit(sr, ' ');
	n = search(*res, save[0], &visited);
	if (n != 1)
	{
		first = ft_strdup(visited->data);
		search_paths(res, &save[0], &first, &path, &las);
	}
	
	else if (n != 1)
	{
		first = ft_strdup(visited->data);
		printf("first == %s", first);
		while (p < 2)
		{
			search_paths(res, &save[0], &first, &path, &las);
			search(*res, save[0], &visited);
			printf("start room == %s\n", save[0]);
			first = ft_strdup(visited->data);
			p++;
		}
		if (search_end(path, en) == 1)
			return (0);
	}
	else if (ft_strcmp("noend", first) == 0)
	{
		delete_n(&path);
		save = ft_strsplit(sr, ' ');
		first = ft_strdup(visited->right->data);
		paths(res, sr, en, las);
	}
	return (path);
}
*/
