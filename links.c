/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:02 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/09/03 09:51:04 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

t_lst    *search_path(t_lst  *res, char *s, char *e)
{
    char **st;
    char **en;
    char **cut;
    t_lst *tmp;
    t_lst *path;

   path = NULL;
    st = ft_strsplit(s, ' ');
    en = ft_strsplit(e, ' ');
        if (path == NULL)
            create_path(&path, st[0]);
        tmp = res;
        int i = 0;
        //cut = NULL;
        while (i++<1)//ft_strcmp(en[0], st[0]) != 0)
        {
   trav(path);
        //ft_putnbr(ft_strcmp(e, (*path)->data));
            while (tmp)
            {
                ft_putendl(ft_strsub(tmp->data, 0, ft_strlen(st[0])));
                if (ft_strcmp(st[0], ft_strsub(tmp->data, 0, ft_strlen(st[0]))) == 0)
                {
    //ft_putendl(tmp->data);
                    cut = ft_strsplit(tmp->data, '-');
                    create_path(&path, cut[1]);
                    ft_putendl(cut[1]);
                    st[0] = cut[1];
                }
                else if ()
                {

                }
                
                tmp = tmp->right;
            }
            if (tmp == NULL)
            {
                while (tmp)
                {
                    if (ft_strcmp(st[0], ft_strsub(tmp->data, 0, ft_strlen(st[0]))) == 0)
                    {
                        cut = ft_strsplit(tmp->data, '-');
                        create_path(&path, cut[1]);
                        st[0] = cut[1];
                    }
                tmp = tmp->left;
                }
            }
            //printf("Len == %d", ft_lstlen(path));
        }
    return (path);
}