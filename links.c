/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:02 by txaba             #+#    #+#             */
/*   Updated: 2019/09/11 17:40:11 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
t_lst *las = NULL;
t_lst *fir = NULL;

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
        fir = temp;
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
    char **firstsignal;
    int i = 0;

   path = NULL;
    st = ft_strsplit(s, ' ');
    firstsignal = ft_strsplit(s, ' ');
    printf("%s\n\n\n", e);
    return(path);
    en = ft_strsplit(e, ' ');
        if (path == NULL)
            create_path(&path, st[0]);
        tmp = res;
        while (1)
        {
       // tmp = res;
            ft_putstr("THE START!! OF FIRST RUN\n");
        trav(tmp);
            while (tmp)
            {
                if (ft_strcmp(st[0],ft_strreturn(tmp->data, st[0])) == 0  /* || st[0] == firstsignal[0] */)
                {
                    cut = ft_strsplit(tmp->data, '-');
                if (isadded(path, cut[1]) == 1 && isadded(path, cut[0]) == 1)
                {
                    //ft_putstr("heeeeeellllllooooo");
                    //return (path);
                    tmp->data = "";
                    //tmp = tmp->right;
                    cut[0] = NULL;
                    cut[1] = NULL;
                    //break;
                }
                    if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])) && cut[0] && cut[1]/* && isadded(path, st[0]) == 0 */)
                    {
                         cut = ft_strsplit(tmp->data, '-');
                        create_path(&path, cut[0]);
                        st[0] = cut[0];
                    }
                    else /* if (isadded(path, st[0]) == 0) */if (cut[0] && cut[1])
                    {
                       create_path(&path, cut[1]);
                        st[0] = cut[1];
                    }
                   // printf("\n\n%s\n\n", st[0]);
                    if (ft_strcmp(pos(path, ft_lstlen(path)), en[0]) == 0)
                        return (path);
                }
                tmp = tmp->right;
            }
            trav(path);
            //return (path);
            ft_putstr("THE END OF FIRST RUN\n");
             if (tmp == NULL)
            {
                tmp = las;
               //trav(tmp);
               //return(path);
                while (tmp)
                {
                    //printf("temp->left = %s\n", tmp->data);
                    trav(tmp);
                    if (ft_strcmp(st[0], ft_strsub(tmp->data, 0, ft_strlen(st[0]))) == 0 || (!cut[0] && !cut[1]))
                    {
                printf("HERE\n");
                        cut = ft_strsplit(tmp->data, '-');
                    if (isadded(path, cut[1]) == 1 && isadded(path, cut[0]) == 1)
                    {
                    tmp->data = "";
                    //tmp = tmp->left;
                    cut[0] = NULL;
                    cut[1] = NULL;
                    //break;
                    //return (path);
                    }
                    printf("my cut === %s\n", cut[1]);
                        if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])) && cut[0] && cut[1])
                        {
                             cut = ft_strsplit(tmp->data, '-');
                            create_path(&path, cut[0]);
                            st[0] = cut[0];
                        }
                        else if (cut[0] && cut[1])
                        { 
                            create_path(&path, cut[1]);
                            st[0] = cut[1];
                        }
                        if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                            return(path);
                    } 
                tmp = tmp->left;
                //printf("\n\n num = %d\n\n\n" , isadded(path, st[0]));
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;      
                }
            }
            trav(path);
            printf("%s\n", en[0]);
            return(path);
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;      
           /* if (i == 1)
           {
              //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               //tmp->data = "--";
               //tmp = tmp->left;
               //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               //tmp = tmp->right;
               //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               //trav(tmp);
               //path->left->right = NULL;
               return (path);
           }  */
           //char **posi;
           //printf("---->>>%s\n", pos(res, ft_lstlen(res)));
           //printf("---->>>%s\n", st[0]);
           
           i++;

            /* posi = ft_strsplit(pos(res, ft_lstlen(res)), '-');
            if (!ft_strcmp(posi[1], en[0]) || !ft_strcmp(posi[0], en[0]))
                break; */
           // break;
        }
        //trav(path);
    return (path);
}//the only problem i have is the end... thats all...
/* ##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end 
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5 */
