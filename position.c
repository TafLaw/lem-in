/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:37:47 by txaba             #+#    #+#             */
/*   Updated: 2019/09/11 17:37:48 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

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

int			isadded(t_lst *path, char *c)
{
	t_lst *tmp;
	tmp = path;
	//trav(tmp);
	while(tmp && ft_lstlen(path) != 1)
	{
		if(ft_strcmp(tmp->data, c) == 0){
		return (1);
		}/* 
	printf("str[0] == %s\n", c);
	printf("tmp->data == %s\n", tmp->data);
 */
		tmp = tmp->right;
	}
	if (tmp == NULL)
		return (0);
	return (0);
}
