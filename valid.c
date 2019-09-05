/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:10 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/09/03 09:51:12 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int     check_input(char **str, int ac)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    
    if((*str[i] >= 9 && *str[i] <= 13) || (*str[i] == 32))
    {
        ft_putendl("Error");
        return (0);
    }
    str = ft_strsplit(*str, ' ');
    if (*str[i] == '#')
        return (1);
    if (ac != 3 || str[0][i] == 'L')
    {
        ft_putendl("Error");
        return (0);
    }
    while (str[2][j] >= '0' && str[2][j] <= '9')
        j++;
    while (str[1][i] >= '0' && str[1][i] <= '9')
        i++;
    if (i == ft_strlen(str[1]) && j == ft_strlen(str[2]))
        return (1);
    ft_putendl("Error");
    return (0);
}

int     main(int ac, char **av)
{
    t_lst   *path;
    t_in *res;
    int i = 0;
    char *in;

    if (ac == 1 && av[1] == NULL)
    {
        if (get_next_line(0, &in) == 1)
        {
            while (in[i])
            {
                if (!ft_isdigit(in[i]))
                {
                    ft_putendl("Error");
                    free(in);
                    return (0);
                }
                else
                    i++;
            }
        }
        ft_strclr(in);
        while ((get_next_line(0, &in) == 1))
        {
            if (word_c(in, ' ') == 3 || (in[0] == '#'))
            {
                if (!check_input(&in, word_c(in, ' ')))
                {
                    free(in);
                    return (0);
                }
            }
            else
            {
                    links(in, &path, &res);
            }
        }
        trav(path);
        free(path);
    free(in);
    }
    return (0);
}
