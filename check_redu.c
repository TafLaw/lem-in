#include "lem_in.h"
//for check
//(create tmp variable to store and end, check input when passed);
int					duplicate(t_in *stack, char *s)
{
	int		up;

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

int					duplicate2(t_lst *stack, char *s)
{
	int		up;

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
