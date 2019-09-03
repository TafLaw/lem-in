
#include "./libft/libft.h"

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
                    return (0);
                }
                else
                    i++;
                
            }
        }
        
        while (get_next_line(0, &in) == 1)
        {
            if (!check_input(&in, word_c(in, ' ')))
                return (0);
        }
    }
    else
    {
        ft_putendl("only one");
    }
    return (0);
}