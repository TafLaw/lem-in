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
    t_in    *tmp;
    t_in    *t;

    tmp = (t_in *)malloc(sizeof(t_in));
    tmp->data = ft_strdup(s);
    tmp->next = NULL;
    if (*p == NULL)
        *p = tmp;
    else
    {
        t = *p;
        while (t->next != NULL)
            t = t->next;
        t->next = tmp;
    }    
}

void    links(char *str, t_lst **path)
{
    char **pre;
    int  i;
    t_in *res;
    
    
    i = 0;
    res = NULL;
    pre = ft_strsplit(str, '-');
    //ft_putstr("Error");
    single_paths(&res, pre[i]);
    trav2(res);
    if (duplicate(res, pre[i]) == 0)
    {
        
        if (*path == NULL)
        {
            create_path(path, pre[i]);
            create_path(path, pre[i+1]);
            
        }
        else 
                create_path(path, pre[i+1]);
      trav(*path);
    }
    if (duplicate(res, pre[i]) == 1)
    {
        return ;
    }
    free(pre);
}