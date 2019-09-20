/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:24:22 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/08/21 11:42:25 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_n(t_lst **top)
{
	t_lst *temp;
	t_lst *link;

	temp = *top;
	while (temp)
	{
		link = temp->right;
		free(temp);
		temp = link;
	}
	*top = NULL;
}
