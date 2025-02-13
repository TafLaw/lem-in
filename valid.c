/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:10 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/09/18 15:37:41 by mnzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int         check_rooms(t_in *room, char *s)
{
    char **r;
    int     val;

    val = 0;
    r = ft_strsplit(s, '-');
    while (room != NULL)
    {
        if (!ft_strcmp(room->data, r[0]) || !ft_strcmp(room->data, r[1]))
            val++;
        if (val == 2)
            return (1);
        room = room->next;
    }
    return (0);
}

void    valid_rooms(t_in **p, char *s)
{
    t_in *temp;
    t_in *t;
    char **in;

    if (s[0] == '#')
        return;
    in = ft_strsplit(s, ' ');
    temp = (t_in *)malloc(sizeof(t_in));
    temp->data = ft_strdup(in[0]);
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

int     def_start_end(t_in **store, char **start, char **end)
{
    t_in *tmp;

    tmp = *store;
    while (tmp != NULL)
    {
        if (ft_strcmp("start", ft_strstr(tmp->data, "start")) == 0)
        {
            tmp = tmp->next;
            if (word_c(tmp->data, ' ') == 3)
            {
                *start = ft_strdup(tmp->data);
                break;
            }
            else 
            {
                ft_putendl("Invalid Start");
                return (0);
            }
        }
        else
            tmp = tmp->next;
    }
    tmp = *store;
    while (tmp != NULL)
    {
        if (ft_strcmp("end", ft_strstr(tmp->data, "end")) == 0)
        {
          //  if (tmp->next)
            tmp = tmp->next;
            if (word_c(tmp->data, ' ') == 3)
            {
                *end = ft_strdup(tmp->data);
                break ;
            }
            else
            {
                ft_putendl("Invalid end");
                return (0);
            }
        }
        else
            tmp = tmp->next;
    }
    return (1);
}

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
    t_lst   *temp;
    t_lst   *path;
    t_in    *store;
    t_lst    *res;
    t_in    *rooms;
    int     i = 0, ants = 0;
    char    *in;
    char *start;
    char *end;
   
    store = NULL;
    path = NULL;
	av = 0;
    if (ac == 1)
    {
        if (get_next_line(0, &in) == 1)
        {
			//ft_putendl(in);
            while (in[i])
            {
                if (ft_isdigit(in[i]) || in[i] == '#')
                    i++;
                else
                {
                    ft_putendl("Error");
                    return (0);                    
                }
                /* if (!ft_isdigit(in[i]))
                {
                    free(in);
                    return (0);
                }
                else
                    i++; */
            }
            ants = ft_atoi(in);
        }
        ft_strclr(in);
        while ((get_next_line(0, &in) == 1))
        {
			//ft_putendl(in);
            if (word_c(in, ' ') == 3 || (in[0] == '#'))
            {
                if (!check_input(&in, word_c(in, ' ')))
                {
                    free(in);
                    return (0);
                }
                valid_rooms(&rooms, in);
                single_paths(&store, in);
           }
            else if (def_start_end(&store, &start, &end) == 0)
               		 return (0);
            		else
            		{
						if (check_rooms(rooms, in) == 1)
                   //single_paths(&res, in);
                   		create_links(&res, in);
                		else
                		{
                    		ft_putendl("Invalid room");
                    		return (0);
                		}
            		}
        	}
        	//printf("\033[0;35m\nStart : %s\nEnd : %s\n\n\033[0m", start, end);
        	path = search_path(res, start, end);
            i = 1;
            temp = path->right;
            //ft_putchar('\n');
            while (temp && i < ants + 1)
            {
                ft_putstr("\nL");
                ft_putnbr(i);
                ft_putstr("-");
                ft_putstr(temp->data);
                ft_putstr(" ");
                if (!temp->right)
                {
                    temp = path->right;
                    //ft_putchar('\n');
                    i++;
                }
                else
                    temp = temp->right;
            }

            sleep(40);
        	//trav(path);
        	delete_n(&path);
    		free(in);
	}
    return (0);
}
