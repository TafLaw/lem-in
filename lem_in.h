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

int             duplicate(t_in *stack, char *s);
void            single_paths(t_in **p, char *s);
void            links(char  *str, t_lst **path);
void	        trav(t_lst *top);
void	        trav2(t_in *top);
#endif