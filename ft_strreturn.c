/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreturn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:14:15 by txaba             #+#    #+#             */
/*   Updated: 2019/09/17 14:14:18 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strreturn(const char *hay, const char *needle)
{
	char **sp;

	sp = ft_strsplit((char*)hay, '-');
	if (ft_strcmp(sp[0], needle) == 0)
	{
		return ((char *)needle);
	}
	else if (ft_strcmp(sp[1], needle) == 0)
	{
		return ((char *)needle);
	}
	return ((char *)hay);
}
