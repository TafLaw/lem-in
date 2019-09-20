/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:03:42 by txaba             #+#    #+#             */
/*   Updated: 2019/09/17 14:07:10 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			duplicate(t_in *stack, char *s)
{
	int	up;

	up = 0;
	while (stack)
	{
		if (!ft_strcmp(stack->data, s))
			up++;
		if (up > 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int			duplicate2(t_lst *stack, char *s)
{
	int	up;

	up = 0;
	while (stack)
	{
		if (!ft_strcmp(stack->data, s))
			up++;
		if (up > 1)
			return (1);
		stack = stack->right;
	}
	return (0);
}
