/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:07:54 by txaba             #+#    #+#             */
/*   Updated: 2019/09/17 14:11:52 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		trav(t_lst *top)
{
	t_lst *temp;

	if (top == NULL)
		ft_putendl("EMPTY");
	else
	{
		temp = top;
		ft_putstr("NULL <- ");
		while (temp != NULL)
		{
			ft_putstr(temp->data);
			ft_putstr(" -> ");
			temp = temp->right;
		}
		ft_putendl("NULL");
	}
}

void		trav2(t_in *top)
{
	t_in *temp;

	if (top == NULL)
		ft_putendl("EMPTY");
	else
	{
		temp = top;
		while (temp != NULL)
		{
			ft_putstr(temp->data);
			ft_putstr(" -> ");
			temp = temp->next;
		}
		ft_putendl("NULL");
	}
}
