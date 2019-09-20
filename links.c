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
//t_lst *las = NULL;

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
        //las = temp;
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

t_lst    *search_path(t_lst  *res, char *s, char *e)
{
    char **st;
    char **en;
    t_lst *tmp;
    t_lst *path;

   path = NULL;
   st = ft_strsplit(s, ' ');
   en = ft_strsplit(e, ' ');
   if (path == NULL)
    create_path(&path, st[0]);
        tmp = top_bot(st[0], en[0], &path, res);
    if (tmp == NULL)
        bot_top(st[0], en[0], &path, res);
        
    return (path);
}