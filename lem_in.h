/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:52:20 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/09/03 09:52:22 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct      s_lst
{
    char           *data;
    struct s_lst   *right;
    struct s_lst   *left;
}               t_lst;

typedef struct      s_lem 
{
    char           *data;
    struct s_lem   *next;
}                   t_in;
void            create_path(t_lst **p, char *da);
char            *ft_strreturn(const char *hay, const char *needle);
char		    *pos(t_lst *a, int loc);
t_lst           *search_path(t_lst  *res, char *s, char *e);
void            create_links(t_lst **p, char *da);
int             duplicate(t_in *stack, char *s);
int             duplicate2(t_lst *stack, char *s);
void            single_paths(t_in **p, char *s);
void            links(char  *str, t_lst **path, t_in **res);//, t_in **res2);
void	        trav(t_lst *top);
void	        trav2(t_in *top);
int             ft_lstlen(t_lst *r);
void	        end_to_end(t_lst **res);
t_lst	*end_to_bottom(t_lst **res, int loc);
int		loc(t_lst *top, char *end);
t_lst		*addr_pos(t_lst *a, int loc);
void		delete_node(t_lst **a, int l);

#endif