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
int      does_link(t_lst *res, char *s, char *end)//take the start and check if it's gonna link to the end.. if yes link end, else move on
{
    char **r;
    char *res_st;
    char *st = ft_strjoin(s, end);
    char *st2 =  ft_strjoin(end, s);

    while (res)
    {
        r = ft_strsplit(res->data, '-');
        res_st = ft_strjoin(r[0], r[1]);
        if (!ft_strcmp(res_st, st) || !ft_strcmp(res_st, st2))
            return (1);
        res = res->right;
    }
    return (0);
}

int      check_links(t_lst *res, char *s)
{
    char    **r;
    int     up;

    up = 0;
    while (res)
    {
        r = ft_strsplit(res->data, '-');
        if (!ft_strcmp(r[0], s) || !ft_strcmp(r[1], s))
            up++;
        res = res->right;
    }
    return (up);
}
int     was_visited(t_lst *v, char *r)
{
    int i = 0;
    while (v)
    {
        if (!ft_strcmp(v->data, r))
            i++;
        if (i >= 2)
            return (2);
        i++;
    }
    return (0);
}
t_lst    *search_path(t_lst  *res, char *s, char *e)
{
    //char **cut2 = NULL;
               // char *prev = NULL;
    //t_lst *visited = NULL;
    char **st;
    char **en;
    char **cut;
    t_lst *tmp;
    t_lst *path;
    t_lst *addr;
    int j = 0, i = 0;

   path = NULL;
    st = ft_strsplit(s, ' ');
    en = ft_strsplit(e, ' ');
        if (path == NULL)
            create_path(&path, st[0]);
        tmp = res;
        while (1)
        {
            while (tmp)
            {
                    printf("\033[0;36mSTART = %s\033[0m\n", st[0]);
                if (ft_strcmp(st[0],ft_strreturn(tmp->data, st[0])) == 0)
                {
                    cut = ft_strsplit(tmp->data, '-');
                    if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])))
                    {
                        cut = ft_strsplit(tmp->data, '-');
                        if (does_link(res, st[0], en[0])){
                            create_path(&path, en[0]);
                            if (duplicate2(path, cut[0]))
                                delete_node(&path, ft_lstlen(path));}
                        else{
                            create_path(&path, cut[0]);
                            if (duplicate2(path, cut[0]))
                                delete_node(&path, ft_lstlen(path));}
                        st[0] = cut[0];
                        addr = addr_pos(tmp, loc(tmp, st[0]));
                        printf("\033[0;33m\n");
                        trav(tmp);
                        printf("\033[0m\n");
                    }
                    else
                    {
                        if (does_link(res, st[0], en[0])){
                            create_path(&path, en[0]);
                            if (duplicate2(path, cut[0]))
                                delete_node(&path, ft_lstlen(path));}
                        else
                        {
                            create_path(&path, cut[1]);
                            if (duplicate2(path, cut[0]))
                                delete_node(&path, ft_lstlen(path));}
                        st[0] = cut[1];
                        addr = addr_pos(tmp, loc(tmp, st[0]));
                         printf("\033[0;34m\n");
                        trav(tmp);
                        printf("\033[0m\n");
                    }
                    trav(path);
                    if (ft_strcmp(pos(path, ft_lstlen(path)), en[0]) ==0){
                        return (path);}
                }
                else
                {
                    printf("\n__________________________________________\nNO true condition found\n\n");
                    trav(addr);
                    printf("\033[0;31mneedle = %s\033[0m\n", st[0]);
                    printf("\033[0;32mhay = %s\033[0m\n_________________________________\n", tmp->data);
                } 
                tmp = tmp->right;
                trav(tmp);
                if (tmp == NULL && ft_strcmp(pos(path, ft_lstlen(path)), en[0]))//the new start should match one of the next link rooms
                {
                    printf("here\n");
                    if (addr->right == NULL)
                        break;
                    tmp = addr->right;
                    delete_node(&path, loc(path, pos(path, ft_lstlen(path)))-1);
                    st[0] = pos(path, ft_lstlen(path));
                    j = i;
                }
                trav(path);
            }
            //return (path);
            if (tmp == NULL)
            {
                tmp = las;
                while (tmp)
                    {
                        if (ft_strcmp(st[0],ft_strreturn(tmp->data, st[0])) == 0)
                        {
                            cut = ft_strsplit(tmp->data, '-');
                            if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])))
                            {
                                cut = ft_strsplit(tmp->data, '-');
                                if (does_link(res, st[0], en[0])){
                                    create_path(&path, en[0]);
                                    if (duplicate2(path, cut[0]))
                                        delete_node(&path, ft_lstlen(path));}
                                else{
                                    create_path(&path, cut[0]);
                                    if (duplicate2(path, cut[0]))
                                        delete_node(&path, ft_lstlen(path));}
                                st[0] = cut[0];
                                addr = addr_pos(tmp, loc(tmp, st[0]));
                            }
                            else
                            {
                                if (does_link(res, st[0], en[0])){
                                    create_path(&path, en[0]);
                                    if (duplicate2(path, cut[0]))
                                        delete_node(&path, ft_lstlen(path));}
                                else
                                {
                                    create_path(&path, cut[1]);
                                    if (duplicate2(path, cut[0]))
                                        delete_node(&path, ft_lstlen(path));}
                                st[0] = cut[1];
                                
                                addr = addr_pos(tmp, loc(tmp, st[0]));
                            }
                            trav(tmp);
                            trav(path);
                            if (ft_strcmp(pos(path, ft_lstlen(path)), en[0]) ==0){
                                return (path);}
                        }
                        tmp = tmp->left;
                        if (tmp == NULL && ft_strcmp(pos(path, ft_lstlen(path)), en[0]))//the new start should match one of the next link rooms
                        {
                            tmp = addr->right;
                            delete_node(&path, loc(path, pos(path, ft_lstlen(path)))-1);
                            st[0] = pos(path, ft_lstlen(path));
                        }
            }}}
    return (path);
}