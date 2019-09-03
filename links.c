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
    else
    {
        t = *p;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
        temp->left = t;
        *p = t;
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

void    links(char *str, t_lst **path)
{
    t_list *paths;
    int i = -1;
    int j = 0;

    char *pre = ft_strnew(p_len(str));
    char *sur = ft_strnew(s_len(str));
    while (str[++i] != '-')
        pre[i] = str[i];
    while (str[++i])
        sur[j++] = str[i];
    if (ft_strcmp(pre, sur))
    {
        create_path(path, pre);
        create_path(path, sur); 
    }
    //paths(single list string paths)
    while ()
    free(pre);
    free(sur);
}
